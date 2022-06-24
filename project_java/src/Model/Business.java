package Model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

/**
 * Classe que contém informação relativa a um business
 */

public class Business implements IBusiness, Serializable {
    private String id;
    private String name;
    private String city;
    private String state;
    private List<String> categories;

    public Business(Business b) {
        this.id = b.getId();
        this.name = b.getName();
        this.city = b.getCity();
        this.state = b.getState();
        this.categories = b.getCategories();
    }

    public Business(String id, String name, String city, String state, List<String> categories) {
        this.id = id;
        this.name = name;
        this.city = city;
        this.state = state;
        this.setCategories(categories);
    }

    /**
     * Método que lê uma linha de um ficheiro e preenche o Business com as respetivas informações
     * @param line linha do ficheiro dos businesses
     * @return um negócio
     */
    public static IBusiness businessFromLine(String line) {
        String[] buffer = line.split(";");
        String[] cats = buffer.length == 5 ? buffer[4].split(",") : new String[0];
        List<String> categories = new ArrayList<>();
        int valid = 1;
        for(int i=0; i<cats.length; i++) categories.add(cats[i]);
        for(int i=0; i<3; i++) {
            if(buffer[i] == null) valid = 0;
        }
        if(valid == 1) return new Business(buffer[0],buffer[1],buffer[2],buffer[3],categories);
        return null;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public List<String> getCategories() {
        return this.categories.stream().collect(Collectors.toList());
    }

    public void setCategories(List<String> categories) {
        this.categories = new ArrayList<>(categories);
    }

    public Business clone() {
        return new Business(this);
    }

    public int hashCode() {
        return Objects.hash(id, name, city, state, categories);
    }
}
