import Controller.Controller;
import Controller.IController;
import Model.GestReviews;
import Model.IGestReviews;
import View.IView;
import View.View;

public class GestReviewsAppMVC {

    public static void main(String args[]) {
        IGestReviews model = new GestReviews();
        IView view = new View();
        IController controller = new Controller(model,view);
        controller.run();
    }
}
