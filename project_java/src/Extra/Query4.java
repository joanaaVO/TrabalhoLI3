package Extra;

import java.util.Map;
import java.util.TreeMap;

public class Query4 {
    private TreeMap<Integer,RatingBusiness> ratings;

    public Query4(){
        this.ratings = new TreeMap<>();
    }

    public TreeMap<Integer, RatingBusiness> getRatings() {
        return ratings;
    }

    public void AddReview(int mes, String userId, double stars){
        if(this.ratings.get(mes) == null){
            RatingBusiness novo = new RatingBusiness();
            this.ratings.put(mes, novo);
        }

        RatingBusiness avalMensal = this.ratings.get(mes);
        avalMensal.addUser(userId);
        avalMensal.addReview();
        avalMensal.addAvaliacao(stars);
    }

    public String toString(){
        String result = "";
        for(Map.Entry<Integer,RatingBusiness> rt : this.ratings.entrySet()){
            String aux =  "\n-------------------\nMes: " + rt.getKey() + "\nTotal Reviews: "
                    + rt.getValue().getTotalReviews()
                    + "\nMedia avaliacoes: "
                    + rt.getValue().getMediaAvaliacao()
                    + "\nUsers unicos: "
                    + rt.getValue().getTotalUniqueUsers();
            result += aux;
        }

        return result;
    }

}