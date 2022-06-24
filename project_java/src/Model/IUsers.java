package Model;

import java.io.IOException;
import java.util.Map;
import java.util.Set;

public interface IUsers {
    Map<String,IUser> getUsers();
    void addUser(IUser u);
    boolean containsUser(String id);
    void readUsers(String filepath) throws IOException;
    Users Clone();
}
