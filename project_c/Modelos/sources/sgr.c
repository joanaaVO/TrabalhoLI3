#include "../Includes/sgr.h"
#include <ctype.h>
#define BUSINESS_PATH "/home/joana/Documents/Uni/LI3/input_files/business_full.csv"
#define USERS_PATH "/home/joana/Documents/Uni/LI3/input_files/users_full.csv"
#define REVIEWS_PATH "/home/joana/Documents/Uni/LI3/input_files/reviews_1M.csv"

struct sgr
{
    USERS users;
    BUSINESSES businesses;
    REVIEWS reviews;
};

SGR init_sgr()
{
    SGR sgr = malloc(sizeof(struct sgr));
    sgr->users = NULL;
    sgr->businesses = NULL;
    sgr->reviews = NULL;

    return sgr;
}

void free_sgr(SGR sgr)
{
    destroyUsers(sgr->users);
    destroyBusinesses(sgr->businesses);
    destroyReviews(sgr->reviews);
    free(sgr);
}

BUSINESSES get_sgr_businesses(SGR sgr)
{
    return sgr->businesses;
}

REVIEWS get_sgr_reviews(SGR sgr)
{
    return sgr->reviews;
}

USERS get_sgr_users(SGR sgr)
{
    return sgr->users;
}

//-----------------------------------query 1---------------------------------------//
SGR load_sgr(char *UsersFilePath, char *BusinessesFilePath, char *ReviewsFilePath)
{

    SGR sgr = init_sgr();

    printf("A ler businesses....\n");
    if (BusinessesFilePath == NULL)
    {
        sgr->businesses = read_businesses(BUSINESS_PATH);
    }
    else
    {
        sgr->businesses = read_businesses(BusinessesFilePath);
    }

    printf("A ler users....\n");
    if (UsersFilePath == NULL)
    {
        sgr->users = read_users(USERS_PATH);
    }
    else
    {
        sgr->users = read_users(UsersFilePath);
    }

    printf("A ler reviews....\n");
    if (ReviewsFilePath == NULL)
    {
        sgr->reviews = read_reviews(sgr, REVIEWS_PATH);
    }
    else
    {
        sgr->reviews = read_reviews(sgr, ReviewsFilePath);
    }
    return sgr;
}

//-----------------------------------QUERY 2-----------------------------------//

TABLE businesses_started_by_letter(SGR sgr, char letter)
{
    TABLE table = init_table_businesses_started_by_letter();
    letter = toupper(letter);

    GList *list = NULL;

    GHashTable* businesses = get_businesses(sgr->businesses);
    list = get_businesses_by_letter(businesses, list, letter);

    GList *l;
    l = list;
    while (l != NULL)
    {
        char* name = (char *)l->data;
        businesses_by_letter_to_table(name, table);
        l = l->next;
    }

    return table;
}

//-----------------------------------QUERY 3-----------------------------------//

TABLE business_info(SGR sgr, char *business_id) {
    TABLE table = init_table_business_info();

    get_name_city_and_state(get_businesses(sgr->businesses), business_id, table);

    BSAUX bsaux = init_business_aux(business_id,business_id,0,0,0);

    num_of_stars_and_reviews(get_reviews_HashTable(sgr->reviews),bsaux);

    stars_and_reviews_to_table(table, bsaux);

    return table;
}

//-----------------------------------QUERY 4-----------------------------------//

TABLE businesses_reviewed(SGR sgr, char *user_id) {
    TABLE table = init_table_businesses_reviewed();

    get_businesses_reviewed_to_table(get_reviews_HashTable(sgr->reviews), get_businesses(sgr->businesses), user_id, table);

    return table;
}

//-----------------------------------QUERY 5-----------------------------------//

TABLE businesses_with_stars_and_city(SGR sgr, float stars, char *city)
{
    TABLE table = init_table_n_or_more_stars_city();

    BSCITY bscity = init_bscity_with_stars_and_city(stars, city);

    businesses_in_city(get_businesses(sgr->businesses), bscity);

    num_of_stars_business(get_reviews_HashTable(sgr->reviews), bscity);

    BSCITY newbs = init_bscity_with_stars_and_city(stars, city);

    get_n_or_more_stars_businesses(bscity, newbs);

    add_to_table(table, newbs);

    return table;
}


//-----------------------------------QUERY 6-----------------------------------//
int sortBusinessesByStars_Func(gpointer a, gpointer b)
{
    BUSINESSES_BY_STARS resA = (BUSINESSES_BY_STARS)a;
    BUSINESSES_BY_STARS resB = (BUSINESSES_BY_STARS)b;

    if (getStars_businesses_by_stars(resA) < getStars_businesses_by_stars(resB))
    { //ordenar decrescente
        return 1;
    }
    return -1;
}

int compare_float(float f1, float f2)
 {
  float precision = 0.001;
  if (((f1 - precision) < f2) && 
      ((f1 + precision) > f2))
   {
    return 1;
   }
  else
   {
    return 0;
   }
 }

//no enuncado na interface do sgr nao tem la o campo city,mas pela descricao do problema assume-me que o correto é existir
TABLE top_businesses_by_city(SGR sgr, int top, char *city){
    //para cada businesse vamos calcular a media de estrelas
    GList *businesses_values = g_hash_table_get_values(get_businesses(sgr->businesses));
    GList *businesses_by_stars_glist = NULL;
    int total_reviews;
    float total_stars;
    float media;
    GHashTable* reviews = get_reviews_HashTable(sgr->reviews);
    //percorrer os businesses
    printf("percorrer os businesses\n");
    while(businesses_values!=NULL){
        BUSINESS business = (BUSINESS)(businesses_values->data);
        if(strcasecmp(getBusinessCity(business),city)==0){

        
            GList * business_reviews_ids = g_hash_table_get_keys(getReviewsIds(business));
            total_reviews=0;
            total_stars=0;
            //percorrer os reviews de cada business
            while(business_reviews_ids!=NULL){
                char *review_id = (char *)(business_reviews_ids->data);
                REVIEW review = g_hash_table_lookup(reviews,review_id);
                
                total_stars+=get_review_stars(review);
                total_reviews++;

                GList *next2 = business_reviews_ids->next;
                business_reviews_ids = next2;
            }
            if(total_reviews>0){
                media = total_stars/total_reviews;
                GList *aux = businesses_by_stars_glist;
                //percorrer a GList resultado
                while(aux!=NULL){
                    BUSINESSES_BY_STARS businesses_by_stars = (BUSINESSES_BY_STARS)(aux->data);
                    if(compare_float(getStars_businesses_by_stars(businesses_by_stars),media))
                    {
                        BUSINESSES_BY_STARS_AUX novo = create_business_aux(getBusinessID(business),getBusinessName(business));
                        g_hash_table_insert(getBusinessesAux_by_stars(businesses_by_stars), getBusinessID(business), novo);
                    }

                    GList *next3 = aux->next;
                    aux = next3;
                }
                if(aux==NULL){
                    BUSINESSES_BY_STARS novo_businesses_by_stars = create_businesses_by_stars(media);
                    BUSINESSES_BY_STARS_AUX novo = create_business_aux(getBusinessID(business),getBusinessName(business));
                    g_hash_table_insert(getBusinessesAux_by_stars(novo_businesses_by_stars), getBusinessID(business), novo);
                    businesses_by_stars_glist = g_list_append(businesses_by_stars_glist, novo_businesses_by_stars);
                }
            }
        }
        GList *next = businesses_values->next;
        businesses_values = next;
    }
    businesses_by_stars_glist = g_list_sort(businesses_by_stars_glist, (GCompareFunc)sortBusinessesByStars_Func);

    TABLE table = init_table_top_businesses(top);

    printf("GLIST TAMANHO %d\n",g_list_length(businesses_by_stars_glist));
    printf("CRIAR TABLE QUERY 6\n");
    int k=0;
    while(businesses_by_stars_glist!=NULL){
        GList *next = businesses_by_stars_glist->next;
        BUSINESSES_BY_STARS businesses_by_star = (BUSINESSES_BY_STARS)(businesses_by_stars_glist->data);
        float stars = getStars_businesses_by_stars(businesses_by_star);
        printf("Stars: %f\n",stars);
        GList *businesses_aux = g_hash_table_get_values(getBusinessesAux_by_stars(businesses_by_star));
        printf("GLIST businesses_aux TAMANHO %d\n",g_list_length(businesses_aux));
        while (businesses_aux != NULL)
        { 
            BUSINESSES_BY_STARS_AUX bus_aux = (BUSINESSES_BY_STARS_AUX)(businesses_aux->data);
            GList *next2 = businesses_aux->next;
            insert_business_by_stars_to_table(table, getName_business_by_stars_aux(bus_aux), getBusinessId_business_by_stars_aux(bus_aux), stars);
            businesses_aux = next2;
            k++;
            if(k==top) break;
        }
        if(k==top) break;
        businesses_by_stars_glist = next;

    }
    
    printf("Adicionado %d\n", get_table_index(table));
    return table;
}



//--------------------------------------query 7----------------------------------//
int sortUsersByStates_Func(gpointer a, gpointer b)
{
    USERSCOMTANTOSSTATES resA = (USERSCOMTANTOSSTATES)a;
    USERSCOMTANTOSSTATES resB = (USERSCOMTANTOSSTATES)b;

    if (resA->numStates < resB->numStates)
    { //ordenar decrescente
        return 1;
    }
    return -1;
}

TABLE international_users(SGR sgr)
{
    GList *userValues = g_hash_table_get_values(get_HashTable_users(sgr->users));
    int j = 0;
    int conta = 0;
    GList *usersByTotalOfStates = NULL;
    while (userValues != NULL)
    { //para cada utilizador da hash table USERS
        GList *next = userValues->next;
        USER user = (USER)(userValues->data);
        int userStates = (int)g_hash_table_size(getStates(user));
        if (userStates > 1)
        {
            char *user_id = getUserID(user);
            GList *aux = usersByTotalOfStates;
            while (aux != NULL)
            {
                GList *next2 = aux->next;
                USERSCOMTANTOSSTATES usersComTantosStates = (USERSCOMTANTOSSTATES)(aux->data);
                if (usersComTantosStates->numStates == (int)g_hash_table_size(getStates(user)))
                {
                    usersComTantosStates->users = g_list_append(usersComTantosStates->users, strdup(user_id));
                    conta++;
                    break;
                }
                aux = next2;
            }
            if (aux == NULL)
            {
                USERSCOMTANTOSSTATES novoUsersComTantosStates = malloc(sizeof(USERSCOMTANTOSSTATES));
                novoUsersComTantosStates->numStates = userStates;
                novoUsersComTantosStates->users = NULL;
                novoUsersComTantosStates->users = g_list_append(novoUsersComTantosStates->users, strdup(user_id));
                usersByTotalOfStates = g_list_append(usersByTotalOfStates, novoUsersComTantosStates);
                conta++;
            }
        }
        j++;
        userValues = next;
    }
    printf("Encontrados %d users com mais de 1 state\n", conta);

    usersByTotalOfStates = g_list_sort(usersByTotalOfStates, (GCompareFunc)sortUsersByStates_Func);

    TABLE table = init_table_users_more_than_one_state(conta);
    printf("table criada\n");

    while (usersByTotalOfStates != NULL)
    {
        GList *next = usersByTotalOfStates->next;
        USERSCOMTANTOSSTATES usersByStates = (USERSCOMTANTOSSTATES)usersByTotalOfStates->data;
        int states = usersByStates->numStates;
        GList *users_ids = usersByStates->users;
        while (users_ids != NULL)
        { //percorrer a lista ligada de users com tantos states visitados
            GList *next2 = users_ids->next;
            add_userId_by_states_to_table(table, (char *)(users_ids->data));
            //printf("STATES %d --- USER_ID: %s\n", states, (char*)(users_ids->data));
            users_ids = next2;
        }
        usersByTotalOfStates = next;
    }

    printf("adicionados a table %d users\n", get_num_users_estado_from_table(table));

    return table;
}

//-----------------------------------QUERY 8-----------------------------------//

TABLE top_businesses_with_category(SGR sgr, int top, char *category)
{
    TABLE table = init_table_n_or_more_category(top);

    BSCITY bscity = init_bscity_with_category(category);

    businesses_in_category(get_businesses(sgr->businesses), bscity);

    num_of_stars_business(get_reviews_HashTable(sgr->reviews), bscity);

    GList *list_stars = NULL;

    list_stars = get_stars_sorted(bscity, list_stars);

    get_top_businesses(list_stars, table, top);

    return table;
}

//-----------------------------------QUERY 9-----------------------------------//
int ocurrences_of_word_in_text(char *text, char *word, int lengthWord)
{
    int i = 0;
    int j = 0;
    int count_word = 0;
    while (text[i] != '\0')
    {

        if (text[i] == word[j])
        {

            while (text[i] == word[j] && word[j] != '\0' && text[i] != '\0')
            {
                i++;
                j++;
            }

            if (j == lengthWord && (text[i] == ' ' || ispunct(text[i]) || text[i] == '\0'))
            {
                count_word++;
            }
        }
        else
        {
            while (text[i] != ' ' && !ispunct(text[i]))
            {
                i++;
                if (text[i] == '\0')
                    break;
            }
        }

        i++;
        j = 0;
    }

    return count_word;
}

int sort_reviewsByWordCount_Func(gpointer a, gpointer b)
{
    REVIEWS_WRD_CNT_AUX resA = (REVIEWS_WRD_CNT_AUX)a;
    REVIEWS_WRD_CNT_AUX resB = (REVIEWS_WRD_CNT_AUX)b;

    if (reviews_by_wordCount_getWordCount(resA) < reviews_by_wordCount_getWordCount(resB))
    { //ordenar decrescente
        return 1;
    }
    return -1;
}

TABLE reviews_with_word(SGR sgr, int top, char *word)
{
    int lengthWord = strlen(word);

    GList *reviews = g_hash_table_get_values(get_reviews_HashTable(sgr->reviews));
    GList *glist_reviewsByWordMatch = NULL;
    int conta = 1;
    int i = 0;
    while (reviews != NULL)
    {
        REVIEW review = (REVIEW)(reviews->data);
        char *text = get_review_text(review);
        int count_word = ocurrences_of_word_in_text(text, word, lengthWord);
        GList *aux = glist_reviewsByWordMatch;
        i++;
        if (count_word > 0) //nao vale a pena contabilizar os que tem 0 ocorrencias
        {

            while (aux != NULL)
            {

                GList *next2 = aux->next;
                REVIEWS_WRD_CNT_AUX reviews_with_word = (REVIEWS_WRD_CNT_AUX)(aux->data);
                if (reviews_by_wordCount_getWordCount(reviews_with_word) == count_word)
                {
                    GHashTable *reviews_ids_Hash = reviews_by_wordCount_getReviewsIdsHash(reviews_with_word);
                    g_hash_table_insert(reviews_ids_Hash, getReview_Id(review), GUINT_TO_POINTER(1));
                    break;
                }
                aux = next2;
            }
            if (aux == NULL)
            {
                REVIEWS_WRD_CNT_AUX novo = malloc(sizeof(REVIEWS_WRD_CNT_AUX));
                reviews_by_wordCount_setWordCount(novo, count_word);
                reviews_by_wordCount_sethash_reviews(novo, getReview_Id(review));
                glist_reviewsByWordMatch = g_list_append(glist_reviewsByWordMatch, novo);
            }
            
        }
        GList *next = reviews->next;
        reviews = next;
    }

    //printf("GLIST tamanho %d\n", g_list_length(glist_reviewsByWordMatch));
    glist_reviewsByWordMatch = g_list_sort(glist_reviewsByWordMatch, (GCompareFunc)sort_reviewsByWordCount_Func);

    TABLE table = table_set_reviews_by_word_count(glist_reviewsByWordMatch, top);

    //char **res = get_reviews_id(table);

    // for (int i = 0; i < top; i++)
    // {
    //     printf("%s\n", res[i]);
    // }

    return table;
}



