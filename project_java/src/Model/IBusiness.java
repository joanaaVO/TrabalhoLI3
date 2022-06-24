package Model;

import java.util.List;

public interface IBusiness {
    String getId();
    void setId(String id);
    String getName();
    void setName(String name);
    String getCity();
    void setCity(String city);
    String getState();
    void setState(String state);
    List<String> getCategories();
    void setCategories(List<String> categories);
    IBusiness clone();
}
