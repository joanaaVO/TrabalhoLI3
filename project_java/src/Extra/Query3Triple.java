package Extra;

public class Query3Triple {
    private int numberOfReviews;
    private int businessesReviewed;
    private float averageGrade;

    public Query3Triple(int numberOfReviews, int businessesReviewed, float averageGrade) {
        this.numberOfReviews = numberOfReviews;
        this.businessesReviewed = businessesReviewed;
        this.averageGrade = averageGrade;
    }

    public int getNumberOfReviews() {
        return numberOfReviews;
    }

    public int getBusinessesReviewed() {
        return businessesReviewed;
    }

    public float getAverageGrade() {
        return averageGrade;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();

        sb.append("{Number of reviews: ");
        sb.append(this.numberOfReviews + "\n");
        sb.append("Businesses reviewed: ");
        sb.append(this.businessesReviewed + "\n");
        sb.append("Average grade: ");
        sb.append(this.averageGrade + "}\n");

        return sb.toString();
    }
}
