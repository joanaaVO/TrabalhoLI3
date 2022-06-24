package Model;

import java.io.Serializable;
import java.util.Objects;

/**
 * Classe que contém informação relativa a um user
 */

public class User implements IUser, Serializable {
    private String id;
    private String name;
    //private List<String> friends;

    public User(User u) {
        this.id = u.getId();
        this.name = u.getName();
    }

    public User(String id, String name) {
        this.id = id;
        this.name = name;
    }

    /**
     * Método que lê uma linha de um ficheiro e preenche o User com as respetivas informações
     * @param line linha do ficheiro dos users
     * @return um utilizador
     */
    public static IUser userFromLine(String line) {
        String[] buffer = line.split(";");
        int valid = 1;
        for(int i=0; i<3; i++) {
            if(buffer[i] == null) valid = 0;
        }
        if(valid == 1) return new User(buffer[0],buffer[1]);
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

    /*
    public List<String> getFriends() {
        return this.friends.stream().collect(Collectors.toList());
    }

    public void setFriends(List<String> friends) {
        this.friends.stream().collect(Collectors.toList());
    }
     */

    public User clone() {
        return new User(this);
    }

    public int hashCode() {
        return Objects.hash(id, name);
    }
}
