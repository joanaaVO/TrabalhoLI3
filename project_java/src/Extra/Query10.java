package Extra;

import Model.IBusiness;
import Model.IBusinesses;
import Model.IReview;
import Model.IReviews;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Query10 implements IQuery {
    public Map<String, Map<String, Map<String,RatingBusiness>>> getBusinesses_porState() {
        return businesses_porState;
    }

    private Map<String, Map<String, Map<String,RatingBusiness>>> businesses_porState;
    private int inseridos;

    public Query10() {
        this.businesses_porState = new HashMap<>();
        this.inseridos = 0;
    }

    public void AddReview(float stars, IBusiness business) {
        this.inseridos++;
        String city = business.getCity();
        String state = business.getState();
        String businessId = business.getId();
        //obter por state
        Map<String, Map<String,RatingBusiness>> porState = this.businesses_porState.get(state);
        if (porState != null) {
            //obter por city
            Map<String,RatingBusiness> ratBusinessByCity = porState.get(city);
            if (ratBusinessByCity != null) { //se city exist
                boolean exists = false;
                RatingBusiness bus = ratBusinessByCity.get(businessId);
                if(bus!=null){
                    bus.addAvaliacao(stars);
                    bus.addReview();
                    exists = true;
                }
                if(!exists){ //se business nao existe nesta city criar um novo e adicionar
                    RatingBusiness newRatBus = new RatingBusiness(business.getId());
                    newRatBus.addAvaliacao(stars);
                    newRatBus.addReview();
                    ratBusinessByCity.put(businessId,newRatBus);
                }
            }
            else{ //se city nao exist criar e adicionar
                Map<String,RatingBusiness> newMap = new HashMap<>();
                RatingBusiness newRatBus = new RatingBusiness(business.getId());
                newRatBus.addAvaliacao(stars);
                newRatBus.addReview();
                newMap.put(businessId, newRatBus);
                this.businesses_porState.get(state).put(city, newMap);
            }
        }
        else{ //se state nao existe
            Map<String, Map<String,RatingBusiness>> newCity = new HashMap<>();
            Map<String,RatingBusiness> newMap = new HashMap<>();
            RatingBusiness newRatBus = new RatingBusiness(business.getId());
            newRatBus.addAvaliacao(stars);
            newRatBus.addReview();
            newMap.put(businessId,newRatBus);
            newCity.put(city,newMap);
            this.businesses_porState.put(state,newCity);
        }
    }

    public IQuery GetResultado() {
        return null;
    }

    public void ImprimirResultado() {
        for(Map.Entry<String, Map<String, Map<String,RatingBusiness>>> states : this.businesses_porState.entrySet()){
            System.out.println("STATE: " + states.getKey() );
            for(Map.Entry<String, Map<String,RatingBusiness>> city : states.getValue().entrySet()){
                System.out.println("\tCITY: " + city.getKey() );
                for(Map.Entry<String,RatingBusiness> business : city.getValue().entrySet()){
                    System.out.println("\t\tBusinessID: " + business.getValue().getBusinessId() + " AVALIACAO: " + business.getValue().getMediaAvaliacao());
                }
            }
        }
    }
}
