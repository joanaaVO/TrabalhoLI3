package Model;

import java.io.IOException;
import java.util.Map;
import java.util.Set;

public interface IBusinesses {
    Map<String, IBusiness> getBusinesses();
    void addBusiness(IBusiness b);
    boolean containsBusiness(String id);
    void readBusinesses(String filepath) throws IOException;
    Businesses Clone();
}
