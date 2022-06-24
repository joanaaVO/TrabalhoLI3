package Model;

import java.io.IOException;
import java.util.Map;
import java.util.Set;

public interface IReviews {
    Set<IReview> getReviews();
    void addReview(IReview r);
    int readReviews(String filepath, IUsers users, IBusinesses businesses) throws IOException;
    int numberOfReviewsByUser(String id);
    Map<Integer,Set<IReview>> reviewsByMonth();
    Reviews Clone();
}
