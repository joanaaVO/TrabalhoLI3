package Extra.Comparators;

import Extra.RatingBusiness;

import java.util.Comparator;

public class RatingBusinessByTotalReviews implements Comparator<RatingBusiness> {
    @Override
    public int compare(RatingBusiness o1, RatingBusiness o2) {
        if(o1.getTotalReviews() > o2.getTotalReviews()){
            return -1;
        }
        return 1;
    }
}
