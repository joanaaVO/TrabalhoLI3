package Extra;

import Model.IReviews;

import java.util.*;

public class Query8 {
    private TreeMap<Integer,String> users_com_mais_businesses;

    public Query8(){
        this.users_com_mais_businesses = new TreeMap<>(Collections.reverseOrder());
    }

    public void Setquery8_result(Map<String, HashSet<String>> usersMap){
        for (Map.Entry<String, HashSet<String>> entry : usersMap.entrySet()){
            int sizeSet = entry.getValue().size();
            users_com_mais_businesses.put(sizeSet,entry.getKey());
        }
    }

    public TreeMap<Integer,String> get_users_com_mais_businesses(){
        return this.users_com_mais_businesses;
    }

    public void toString_top(int X){
        int i;
        for (i=0;i<X;i++){

        }

        for(Map.Entry<Integer, String> entry : this.users_com_mais_businesses.tailMap(this.users_com_mais_businesses.size() - X).entrySet()){
            System.out.println("USER: " + entry.getValue() + " Number of reviews: " +  entry.getKey());
        }

    }

}
