package Extra;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class RatingBusiness {


    private String businessId;
    private int totalReviews;
    private HashSet<String> users;
    private List<Double> avaliacoes;

    public RatingBusiness(){
        this.totalReviews = 0;
        this.users = new HashSet<>();
        this.avaliacoes = new ArrayList<>();
    }

    public RatingBusiness(String businessId){
        this.businessId = businessId;
        this.totalReviews = 0;
        this.users = new HashSet<>();
        this.avaliacoes = new ArrayList<>();
    }

    public void addReview(){
        this.totalReviews++;
    }

    public void addUser(String user){
        this.users.add(user);
    }

    public void addAvaliacao(double stars){
        this.avaliacoes.add(stars);
    }

    public String getBusinessId() {
        return businessId;
    }
    public int getTotalReviews() {
        return totalReviews;
    }

    public int getTotalUniqueUsers() {
        return this.users.size();
    }

    public HashSet<String> getUsers() {
        return users;
    }

    public double getMediaAvaliacao() {
        return this.avaliacoes.stream().mapToDouble(d -> d).average().orElse(0.0);
    }
}
