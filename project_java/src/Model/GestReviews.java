package Model;

import Extra.*;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Classe agregadora das estruturas do Model.
 */

public class GestReviews implements IGestReviews, Serializable {
    private IUsers users;
    private IBusinesses businesses;
    private IReviews reviews;
    private List<String> ultimosFicheirosLidos;
    private int reviewsErradas;
    private Query10 query10;


    public GestReviews() {
        this.users = new Users();
        this.businesses = new Businesses();
        this.reviews = new Reviews();
        this.ultimosFicheirosLidos = new ArrayList<>();
        this.reviewsErradas = 0;
    }

    /**
     *
     * @param usfile Ficheiro com informações dos users
     * @param bsfile Ficheiro com informações dos businesses
     * @param rvfile Ficheiro com as informações das reviews
     * @throws IOException
     */
    public void readFromFiles(String usfile, String bsfile, String rvfile) throws IOException {
        this.users.readUsers(usfile);
        this.businesses.readBusinesses(bsfile);
        this.reviewsErradas = this.reviews.readReviews(rvfile, users, businesses);
        this.ultimosFicheirosLidos.add(usfile);
        this.ultimosFicheirosLidos.add(bsfile);
        this.ultimosFicheirosLidos.add(rvfile);
    }

    public Set<String> query1() {
        Set<String> bus = this.businesses.getBusinesses().keySet(); //set com os códigos dos businesses
        Set<String> aux = new TreeSet<>();
        for(IReview rv : reviews.getReviews()) {
            aux.add(rv.getBusinessID());
        }
        Set<String> res = new TreeSet<>();
        for(String s : bus) {
            if(!aux.contains(s)) res.add(s);
        }
        return res;
    }

    public Query2 query2(int mes, int ano){
        //percorrer os reviews
        int n_reviews = 0;
        Set<String> users = new HashSet<>();
        for(IReview review: this.reviews.getReviews()) {
            //se encaixar na data
            if (review.getDate().getMonth().getValue() == mes && review.getDate().getYear() == ano) {
                //incrementamos o numero de reviews
                n_reviews++;
                //adicionamos o userID ao SET (elementos unicos)
                users.add(review.getUserID());
            }
        }
        //criar a classe query2 com o numero de reviews + numero de users (tamanho do set)
        Query2 query = new Query2(n_reviews,users.size());
        return  query;
    }

    public Map<Integer, Query3Triple> query3(String id) {
        Map<Integer,Query3Triple> res = new HashMap<>();
        Map<Integer,Set<IReview>> resByMonth = reviews.reviewsByMonth();
        for(Integer m : resByMonth.keySet()) {
            int nReviews = 0;
            Set<String> bus = new HashSet<>();
            float stars = 0;
            int total = 0;
            for(IReview rv : resByMonth.get(m)) {
                if(id.equals(rv.getUserID())) {
                    nReviews++;
                    bus.add(rv.getBusinessID());
                    stars += rv.getStars();
                    total++;
                }
            }
            float avg = stars/total;
            int nBusinesses = bus.size();
            Query3Triple triple = new Query3Triple(nReviews,nBusinesses,avg);
            res.put(m,triple);
        }
        return res;
    }

    public Query4 query4(String businessId){
        Query4 query= new Query4();
        //percorrer os reviews
        for(IReview review: this.reviews.getReviews()) {
            //se businessID for igual
            if(review.getBusinessID().equals(businessId)){
                int mes = review.getDate().getMonth().getValue();
                String userId = review.getUserID();
                double stars = review.getStars();
                query.AddReview(mes,userId,stars);
            }
        }
        return query;
    }

    public Set<Query5Pair> query5(String userID) {
        Set<Query5Pair> res = new TreeSet<>(Query5Pair::compareTo);
        Map<String,Integer> aux = new TreeMap<>();
        Map<String, IBusiness> bizs = businesses.getBusinesses();
        for(IReview rv : reviews.getReviews()) {
            if(userID.equals(rv.getUserID())) {
                String name = bizs.get(rv.getBusinessID()).getName();
                if (aux.containsKey(name)) {
                    int num = aux.get(name);
                    aux.replace(name, num+1);
                } else aux.put(name, 1);
            }
        }
        for(Map.Entry<String, Integer> pair : aux.entrySet()) {
            Query5Pair p = new Query5Pair(pair.getKey(), pair.getValue());
            res.add(p);
        }
        return res;
    }

    // Determinar o conjunto dos X negócios mais avaliados (com mais reviews) em cada ano
    public Query6 query6(int X){
        Query6 query = new Query6();
        for(IReview review : this.reviews.getReviews()){
            int ano = review.getDate().getYear();
            String businessID = review.getBusinessID();
            String userId = review.getUserID();

            query.AddQuery6Entry(ano,businessID,userId);
        }
        query.getBusinesPorAnoSortedByReviews();

        return query;
    }

    public Map<String,List<IBusiness>> query7() {
        Map<String,List<IBusiness>> res = new HashMap<>();
        Map<String,Map<IBusiness,Integer>> aux = new HashMap<>();
        Map<String, IBusiness> bizs = businesses.getBusinesses();
        for(IReview rv : reviews.getReviews()) {
            IBusiness bs = bizs.get(rv.getBusinessID());
            String city = bs.getCity();
            if(aux.containsKey(city)) {
                if(aux.get(city).containsKey(bs)) {
                    int num = aux.get(city).get(bs);
                    aux.get(city).replace(bs,num+1);
                }
                else aux.get(city).put(bs,1);
            }
            else {
                Map<IBusiness,Integer> bsList = new HashMap<>();
                bsList.put(bs,1);
                aux.put(city,bsList);
            }
        }
        for(String c : aux.keySet()) {
            List<IBusiness> bus = aux.get(c).entrySet().stream().sorted((v1,v2) -> v2.getValue()-v1.getValue()).limit(3).map(b -> b.getKey().clone()).collect(Collectors.toList());
            res.put(c,bus);
        }
        return res;
    }

    public Query8 query8(){
        Query8 query8 = new Query8();
        Map<String, HashSet<String>> businesseReviews_byUser = new HashMap<>();
        for (IReview r : this.reviews.getReviews()){
            String user_id = r.getUserID();
            String business_id = r.getBusinessID();
            //se o user existir businesseReviews_byUser
            if(businesseReviews_byUser.containsKey(user_id)){
                //e so inserir ao seu hashset
                businesseReviews_byUser.get(user_id).add(business_id);
            }
            else{
                HashSet<String> newbusinesses = new HashSet<>();
                newbusinesses.add(business_id);
                businesseReviews_byUser.put(user_id,newbusinesses);
            }
        }
        query8.Setquery8_result(businesseReviews_byUser);

        return query8;
    }

    public Set<Query9Pair> query9(String bsID, int x) {
        Set<Query9Pair> res = new TreeSet<>();
        Map<IUser,List<Float>> aux = new HashMap<>();
        Map<String, IUser> us = this.users.getUsers();
        for(IReview rv : this.reviews.getReviews()) {
            if (bsID.equals(rv.getBusinessID())) {
                IUser user = us.get(rv.getUserID());
                if (aux.containsKey(user)) {
                    aux.get(user).add(rv.getStars());
                }
                else {
                    List<Float> stars = new ArrayList<>();
                    stars.add(rv.getStars());
                    aux.put(user, stars);
                }
            }
        }
        for(Map.Entry<IUser, List<Float>> pair : aux.entrySet()) {
            float total = 0;
            for(float st : pair.getValue()) total += st;
            Query9Pair p = new Query9Pair(pair.getKey(), total/pair.getValue().size());
            res.add(p);
        }
        return res.stream().sorted(Query9Pair::compareTo).limit(x).collect(Collectors.toCollection(TreeSet::new));
    }

    public Query10  query10(){
        if(this.query10 != null) return this.query10;

        this.query10 = new Query10();
        Map<String, IBusiness> businesses = this.businesses.getBusinesses();
        for(IReview rv : this.reviews.getReviews()) {
            float stars = rv.getStars();
            IBusiness business = businesses.get(rv.getBusinessID());
            if(business != null){
                this.query10.AddReview(stars,business);
            }
        }

        return this.query10;
    }

    /**
     * Método que permite obter os últimos ficheiros lidos
     * @return uma lista com os ficheiros de users, businesses e reviews
     */
    public List<String> getUltimosFicheirosLidos() {
        return this.ultimosFicheirosLidos.stream().toList();
    }

    public int getReviewsErradas() {
        return reviewsErradas;
    }

    public int getTotalNegocios() {
        return this.businesses.getBusinesses().size();
    }

    public int numOfUsers() {
        return this.users.getUsers().size();
    }

    /**
     * Percorre as reviews e adiciona a um set todos os IDs de users
     * @return o tamanho do set
     */
    public int numOfUsersWithReviews() {
        return this.reviews.getReviews().stream().map(rv -> rv.getUserID()).collect(Collectors.toSet()).size();
    }

    /**
     * Percorre as reviews e procura aquelas cuja soma de cool, funny e useful for igual a 0, guardando-as num set
     * @return tamanho do set
     */
    public int reviewsZeroImpacto() {
        return this.reviews.getReviews().stream().filter(rv -> rv.getCool() + rv.getFunny() + rv.getUseful() == 0).collect(Collectors.toSet()).size();
    }

    /**
     * Método que associa a cada mês o número de reviews que foram feitas neste
     */
    public Map<Integer,Integer> totalReviewsByMonth() {
        Map<Integer,Integer> res = new HashMap<>();
        Map<Integer,Set<IReview>> reviewsByMonth = this.reviews.reviewsByMonth();
        for(Map.Entry<Integer,Set<IReview>> m : reviewsByMonth.entrySet()) {
            res.put(m.getKey(),m.getValue().size());
        }
        return res;
    }

    /**
     * Método que associa a cada mês a classificação média das reviews feitas nesse mesmo mês
     */
    public Map<Integer,Float> averageReviewsGradeByMonth() {
        Map<Integer,Float> res = new HashMap<>();
        Map<Integer,Set<IReview>> reviewsByMonth = this.reviews.reviewsByMonth();
        for(Integer month : reviewsByMonth.keySet()) {
            float stars = 0;
            int total = reviewsByMonth.get(month).size();
            for(IReview rv : reviewsByMonth.get(month)) {
                stars += rv.getStars();
            }
            res.put(month,stars/total);
        }
        return res;
    }

    /**
     * Calcula a classificação média com base em todas as reviews realizadas
     */
    public float globalReviewsGrade() {
        float stars = 0;
        Set<IReview> revs = this.reviews.getReviews();
        int nrReviews = revs.size();
        for(IReview rv : revs) {
            stars += rv.getStars();;
        }
        return stars/nrReviews;
    }

    /**
     * Associa a cada mês o número de users que realizaram reviews nesse mês
     */
    public Map<Integer, Integer> usersReviewedByMonth() {
        Map<Integer,Integer> res = new HashMap<>();
        Map<Integer,Set<IReview>> reviewsByMonth = this.reviews.reviewsByMonth();
        for(Integer m : reviewsByMonth.keySet()) {
            Set<String> us = new HashSet<>();
            for(IReview rv : reviewsByMonth.get(m)) {
                us.add(rv.getUserID());
            }
            res.put(m, us.size());
        }
        return res;
    }

    public boolean existsUser(String id) {
        return this.users.getUsers().containsKey(id);
    }

    public boolean existsBusiness(String id) {
        return this.businesses.getBusinesses().containsKey(id);
    }

    public IUsers getUsers() {
        return this.users.Clone();
    }

    public IBusinesses getBusinesses() {
        return this.businesses.Clone();
    }

    public IReviews getReviews() {
        return this.reviews.Clone();
    }
}
