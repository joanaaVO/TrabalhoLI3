package Model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Catálogo de users
 */
public class Users implements IUsers, Serializable {
    private Map<String, IUser> users;

    public Users() {
        this.users = new HashMap<>();
    }

    public Users(Users users){
        this.users = users.getUsers();
    }

    public Map<String,IUser> getUsers() {
        return users.values().stream().collect(Collectors.toMap(IUser::getId, IUser::clone));
    }

    public void addUser(IUser u) {
        this.users.put(u.getId(),u);
    }

    public boolean containsUser(String id) {
        return this.users.containsKey(id);
    }

    /**
     * Método que lê de um ficheiro as informações relativas a todos os users e os adiciona ao catálogo
     * @param filepath Ficheiro de users
     * @throws IOException
     */
    public void readUsers(String filepath){
        String usInfo;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filepath));
            while((usInfo = br.readLine()) != null) {
                IUser user = User.userFromLine(usInfo);
                if (user != null) users.put(user.getId(),user);
            }
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }

    public Users Clone(){
        return new Users(this);
    }

    public int hashCode() {
        return Objects.hash(users);
    }
}
