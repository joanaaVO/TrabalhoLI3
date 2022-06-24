package Extra;

public class Query2 {
    private int totalReviews;
    private int totalUsersUnique;

    public Query2(int totalReviews, int totalUsersUnique) {
        this.totalReviews = totalReviews;
        this.totalUsersUnique = totalUsersUnique;
    }

    public int getTotalReviews() {
        return totalReviews;
    }

    public int getTotalUsersUnique() {
        return totalUsersUnique;
    }
}
