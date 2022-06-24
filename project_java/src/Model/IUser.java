package Model;

import java.util.List;

public interface IUser {
    String getId();
    void setId(String id);
    String getName();
    void setName(String name);
    //public List<String> getFriends();
    //public void setFriends(List<String> friends);
    IUser clone();
}
