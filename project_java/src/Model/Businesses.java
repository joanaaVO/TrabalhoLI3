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

public class Businesses implements IBusinesses, Serializable {
    private Map<String, IBusiness> businesses;

    public Businesses() {
        this.businesses = new HashMap<>();
    }

    public Businesses(Businesses businesses){
        this.businesses = businesses.getBusinesses();
    }

    public Map<String, IBusiness> getBusinesses() {
        return businesses.values().stream().collect(Collectors.toMap(IBusiness::getId, IBusiness::clone));
    }

    public void addBusiness(IBusiness b) {
        this.businesses.put(b.getId(),b);
    }

    public boolean containsBusiness(String id) {
        return this.businesses.containsKey(id);
    }

    /**
     * Método que lê de um ficheiro as informações relativas a todos os businesses e os adiciona ao catálogo
     * @param filepath Ficheiro de businesses
     * @throws IOException
     */
    public void readBusinesses(String filepath) throws IOException {
        String bsInfo;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filepath));
            while((bsInfo = br.readLine()) != null) {
                IBusiness business = Business.businessFromLine(bsInfo);
                if (business != null) businesses.put(business.getId(),business);
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }

    public Businesses Clone(){
        return new Businesses(this);
    }

    public int hashCode() {
        return Objects.hash(businesses);
    }
}
