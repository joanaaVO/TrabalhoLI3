package Model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Catálogo de businesses
 */

public class Reviews implements IReviews, Serializable {
    private Set<IReview> reviews;

    public Reviews() {
        this.reviews = new HashSet<>();
    }

    public Reviews(Reviews reviews){
        this.reviews = reviews.getReviews();
    }

    public Set<IReview> getReviews() {
        return this.reviews.stream().map(IReview::clone).collect(Collectors.toSet());
    }

    public void addReview(IReview r) {
        this.reviews.add(r);
    }

    /**
     * Método que lê de um ficheiro as informações relativas a todos as reviews e as adiciona ao catálogo
     * @param filepath Ficheiro de reviews
     * @param users catálogo de users
     * @param businesses catálogo de businesses
     * @return número de reviews inválidas
     * @throws IOException
     */
    public int readReviews(String filepath, IUsers users, IBusinesses businesses) throws IOException {
        String rvInfo;
        int reviewsInvalidas = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filepath));
            rvInfo = br.readLine(); //saltar cabeçalho
            while((rvInfo = br.readLine()) != null) {
                IReview review = Review.reviewFromLine(rvInfo,users,businesses);
                if (review != null) reviews.add(review);
                else reviewsInvalidas++;
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
        return reviewsInvalidas;
    }

    /**
     * Método que retorna o número de reviews feito por um utilizador
     * @param id ID de um User
     */

    public int numberOfReviewsByUser(String id) {
        int conta = 0;
        for(IReview rv : this.reviews) {
            if(id.equals(rv.getUserID())) conta++;
        }
        return conta;
    }

    /**
     * Método que associa a cada mês um Set com todas as reviews feitas nesse mês
     */
    public Map<Integer,Set<IReview>> reviewsByMonth() {
        Map<Integer,Set<IReview>> res = new HashMap<>();
        for(IReview rv : this.reviews) {
            int month = rv.getDate().getMonthValue();
            if(res.containsKey(month)) res.get(month).add(rv);
            else {
                Set<IReview> reviews = new HashSet<>();
                reviews.add(rv);
                res.put(month,reviews);
            }
        }
        return res;
    }

    public Reviews Clone(){
        return new Reviews(this);
    }

    public int hashCode() {
        return Objects.hash(reviews);
    }
}
