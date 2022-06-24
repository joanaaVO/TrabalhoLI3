package Extra;

import Model.GestReviews;
import Model.IGestReviews;

import java.io.*;
import java.util.Scanner;

public class WriteReadGestReviews {

    public static void WriteGestReview(String path, IGestReviews gestReviews) {
        try {
            FileOutputStream file = new FileOutputStream(new File(path));
            ObjectOutputStream object = new ObjectOutputStream(file);
            object.writeObject(gestReviews);
            object.close();
            file.close();
        } catch (IOException e) {
            System.out.println("Erro na escrita do objecto em ficheiro " + e.getMessage());
        }
    }

    public static IGestReviews ReadGestReview(String path) {
        try {
            FileInputStream fi = new FileInputStream(new File(path));
            ObjectInputStream oi = new ObjectInputStream(new BufferedInputStream(fi));
            return  ((IGestReviews) oi.readObject());
        } catch (FileNotFoundException e) {
            System.out.println("Ficheiro não encontrado");
        } catch (IOException e) {
            System.out.println("Error initializing stream");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }
}
