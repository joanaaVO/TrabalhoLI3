package Model;

import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.ZoneId;
import java.util.Objects;

/**
 * Classe que contém informação relativa a um user
 */

public class Review implements IReview, Serializable {
    private static final String dateFormat = "yyyy-MM-dd HH:mm:ss";//2014-10-11 03:34:02
    private static final SimpleDateFormat dateParser = new SimpleDateFormat(dateFormat);
    private String id;
    private String userID;
    private String businessID;
    private float stars;
    private int useful;
    private int funny;
    private int cool;
    private LocalDate date;
    private String text;

    public Review(Review r) {
        this.id = r.getId();
        this.userID = r.getUserID();
        this.businessID = r.getBusinessID();
        this.stars = r.getStars();
        this.useful = r.getUseful();
        this.funny = r.getFunny();
        this.cool = r.getCool();
        this.date = r.getDate();
        this.text = r.getText();
    }

    public Review(String id, String userID, String businessID, float stars, int useful, int funny, int cool, LocalDate date, String text) {
        this.id = id;
        this.userID = userID;
        this.businessID = businessID;
        this.stars = stars;
        this.useful = useful;
        this.funny = funny;
        this.cool = cool;
        this.date = date;
        this.text = text;
    }

    /**
     * Método que lê uma linha de um ficheiro e preenche a Review com as respetivas informações
     * @param line linha dos ficheiro das reviews
     * @param users catálogo de users
     * @param businesses catálogo de businesses
     * @return uma review
     */
    public static IReview reviewFromLine(String line, IUsers users, IBusinesses businesses) {
        String[] buffer = line.split(";");
        int valid = 1;
        for(int i=0; i<9; i++) {
            if(buffer[i] == null) valid = 0;
            else if(i == 1 && !users.containsUser(buffer[i])) valid = 0;
            else if(i == 2 && !businesses.containsBusiness(buffer[i])) valid = 0;
        }
        if(valid == 1) {
            float stars = Float.parseFloat(buffer[3]);
            int useful = Integer.parseInt(buffer[4]);
            int funny = Integer.parseInt(buffer[5]);
            int cool = Integer.parseInt(buffer[6]);
            LocalDate date = null;
            try{
                date = dateParser.parse(buffer[7]).toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
            }
            catch (Exception ex){
                System.out.println(ex);
            }
            return new Review(buffer[0],buffer[1],buffer[2],stars,useful,funny,cool,date,buffer[8]);
        }
        return null;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getUserID() {
        return userID;
    }

    public void setUserID(String userID) {
        this.userID = userID;
    }

    public String getBusinessID() {
        return businessID;
    }

    public void setBusinessID(String businessID) {
        this.businessID = businessID;
    }

    public float getStars() {
        return stars;
    }

    public void setStars(float stars) {
        this.stars = stars;
    }

    public int getUseful() {
        return useful;
    }

    public void setUseful(int useful) {
        this.useful = useful;
    }

    public int getFunny() {
        return funny;
    }

    public void setFunny(int funny) {
        this.funny = funny;
    }

    public int getCool() {
        return cool;
    }

    public void setCool(int cool) {
        this.cool = cool;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }

    public Review clone() {
        return new Review(this);
    }

    public int hashCode() {
        return Objects.hash(id, userID, businessID, stars, useful, funny, cool, date, text);
    }
}
