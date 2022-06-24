package Model;

import java.time.LocalDate;

public interface IReview {
    String getId();
    void setId(String id);
    String getUserID();
    void setUserID(String userID);
    String getBusinessID();
    void setBusinessID(String businessID);
    float getStars();
    void setStars(float stars);
    int getUseful();
    void setUseful(int useful);
    int getFunny();
    void setFunny(int funny);
    int getCool();
    void setCool(int cool);
    LocalDate getDate();
    void setDate(LocalDate date);
    String getText();
    void setText(String text);
    IReview clone();
}
