package Model;

import Extra.*;

import java.io.IOException;
import java.util.List;
import java.util.Map;
import java.util.Set;

public interface IGestReviews {
    void readFromFiles(String usfile, String bsfile, String rvfile) throws IOException;
    Set<String> query1();
    Query2 query2(int mes, int ano);
    Map<Integer, Query3Triple> query3(String id);
    Query4 query4(String businessId);
    Set<Query5Pair> query5(String userID);
    Query6 query6(int X);
    Map<String, List<IBusiness>> query7();
    Query8 query8();
    Set<Query9Pair> query9(String bsID, int x);
    Query10 query10();
    List<String> getUltimosFicheirosLidos();
    int getReviewsErradas();
    int getTotalNegocios();
    int numOfUsers();
    int numOfUsersWithReviews();
    int reviewsZeroImpacto();
    Map<Integer,Integer> totalReviewsByMonth();
    Map<Integer,Float> averageReviewsGradeByMonth();
    float globalReviewsGrade();
    Map<Integer, Integer> usersReviewedByMonth();
    boolean existsUser(String id);
    boolean existsBusiness(String id);
    IUsers getUsers();
    IBusinesses getBusinesses();
    IReviews getReviews();
}
