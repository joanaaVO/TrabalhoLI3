package Extra;

import Extra.Comparators.RatingBusinessByTotalReviews;

import java.util.*;

public class Query6 {
    private TreeMap<Integer, TreeMap<String, RatingBusiness>> businessPorAno;
    private TreeMap<Integer, TreeSet<RatingBusiness>> businesPorAnoSortedByReviews;

    public Query6(){
        this.businessPorAno = new TreeMap<>();
        this.businesPorAnoSortedByReviews = null;
    }

    public void AddQuery6Entry(int ano, String businessId, String userId){
        if(!this.businessPorAno.containsKey(ano)){
            TreeMap<String, RatingBusiness> novaEntrada = new TreeMap<>();
            RatingBusiness novoRatingBusiness = new RatingBusiness(businessId);
            novaEntrada.put(businessId,novoRatingBusiness);
            this.businessPorAno.put(ano,novaEntrada);
        }
        else if(!this.businessPorAno.get(ano).containsKey(businessId)){
            this.businessPorAno.get(ano).put(businessId, new RatingBusiness(businessId));
        }

        this.businessPorAno.get(ano).get(businessId).addReview();
        this.businessPorAno.get(ano).get(businessId).addUser(userId);
    }

    public TreeMap<Integer, TreeSet<RatingBusiness>> getBusinesPorAnoSortedByReviews() {
        if(this.businesPorAnoSortedByReviews == null){
            this.businesPorAnoSortedByReviews = new TreeMap<>();
            for(Map.Entry<Integer,TreeMap<String, RatingBusiness>> rt : this.businessPorAno.entrySet()){
                int ano = rt.getKey();
                TreeSet<RatingBusiness> busSortedByReviews = new TreeSet<>(new RatingBusinessByTotalReviews());
                for(Map.Entry<String, RatingBusiness> business : rt.getValue().entrySet()){
                    busSortedByReviews.add(business.getValue());
                }
                this.businesPorAnoSortedByReviews.put(ano,busSortedByReviews);
            }
        }

        return this.businesPorAnoSortedByReviews;
    }
}
