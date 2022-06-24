package Testes;

import Extra.Crono;
import Extra.WriteReadGestReviews;
import Model.*;
import View.View;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Tests implements ITests {
    private static final String BusinessesFile = "src/Extra/Ficheiros/business_full.csv";
    private static final String UsersFile = "src/Extra/Ficheiros/users_full.csv";
    private static final String ReviewsFile = "src/Extra/Ficheiros/reviews_1M.csv";
    private static final String ObjectFile = "backup";
    private static final int mesDefault = 11;
    private static final int anoDefault = 2020;
    private static final String userIdDefault = "RtGqdDBvvBCjcu5dUqwfzA"; //top user do resultado da query 8
    private static final String businessIdDefault = "dr9PgB_kTp998OYWixJYAw"; //top business do resultado da query 6
    private static final int topDefault = 10;
    private IGestReviews gestReviews;
    private IUsers users;
    private IBusinesses businesses;
    private View view;

    public Tests() {
        //view.message();("A criar ambiente de testes (carregar estruturas)");
        this.gestReviews = null;
        this.view = new View();
        /*try {
            this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            view.message();("Ambiente de testes criado");
        } catch (IOException e) {
            view.message();(e);
        }*/
    }

    public double LeituraFicheirosCSV() {
        double usersTotal = LeituraFicheirosUsersCSV();
        double busTotal = LeituraFicheirosBusinessesCSV();
        double revTotal = LeituraFicheirosReviewsCSV();
        return usersTotal + busTotal + revTotal;
    }

    public double LeituraFicheirosUsersCSV() {
        this.users = new Users();
        try {
            Crono.start();
            this.users.readUsers(UsersFile);
            return Crono.stop();
        } catch (IOException exception) {
            view.message(exception.getMessage());
            return 0;
        }
    }

    public double LeituraFicheirosBusinessesCSV() {
        this.businesses = new Businesses();
        try {
            Crono.start();
            this.businesses.readBusinesses(BusinessesFile);
            long businessesEnd = System.currentTimeMillis();
            return Crono.stop();
        } catch (IOException exception) {
            view.message(exception.getMessage());
            return 0;
        }
    }

    public double LeituraFicheirosReviewsCSV() {
        IReviews reviews = new Reviews();
        try {
            if (this.businesses != null && this.users != null) {
                Crono.start();
                reviews.readReviews(ReviewsFile, this.users, this.businesses);
                return Crono.stop();
            } else {
                this.users = new Users();
                this.users.readUsers(UsersFile);
                this.businesses = new Businesses();
                this.businesses.readBusinesses(BusinessesFile);
                Crono.start();
                reviews.readReviews(ReviewsFile, this.users, this.businesses);
                return Crono.stop();
            }
        } catch (IOException exception) {
            view.message(exception.getMessage());
            return 0;
        }
    }

    public double EscritaEmFicheiroGestReview() {
        if (this.gestReviews == null) {
            this.gestReviews = new GestReviews();
            try {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
                Crono.start();
                WriteReadGestReviews.WriteGestReview(ObjectFile, this.gestReviews);
                return Crono.stop();

            } catch (IOException e) {
                view.message(e.getMessage());
            }
        }
        return 0;
    }

    public double LeituraparaMemoriaFicheiroGestReview(String path) {
        Crono.start();
        IGestReviews gestReviews = WriteReadGestReviews.ReadGestReview(path);
        if (gestReviews != null) {
            return Crono.stop();
        }

        return 0;
    }

    public double Query1() {
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query1();
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query2() {
        boolean usarValoresInput = UsarValoresInput();
        int mes, ano;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("Mes:");
            mes = scanner.nextInt();
            view.message("Ano");
            ano = scanner.nextInt();
        } else {
            mes = mesDefault;
            ano = anoDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query2(mes, ano);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query3() {
        boolean usarValoresInput = UsarValoresInput();
        String UserId;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("userId:");
            UserId = scanner.nextLine();
        } else {
            UserId = userIdDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query3(UserId);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query4() {
        boolean usarValoresInput = UsarValoresInput();
        String businessId;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("BusinessId:");
            businessId = scanner.nextLine();
        } else {
            businessId = businessIdDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query4(businessId);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query5() {
        boolean usarValoresInput = UsarValoresInput();
        String UserId;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("userId:");
            UserId = scanner.nextLine();
        } else {
            UserId = userIdDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query5(UserId);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query6() {
        boolean usarValoresInput = UsarValoresInput();
        int top;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("Top:");
            top = scanner.nextInt();
        } else {
            top = topDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query6(top);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query7() {
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query7();
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query8() {
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query8();
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query9() {
        boolean usarValoresInput = UsarValoresInput();
        String businessId;
        int top;
        if (usarValoresInput) {
            Scanner scanner = new Scanner(System.in);
            view.message("Business Id:");
            businessId = scanner.nextLine();
            view.message("Top:");
            top = scanner.nextInt();
        } else {
            businessId = businessIdDefault;
            top = topDefault;
        }
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query9(businessId, top);
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public double Query10() {
        try {
            if (this.gestReviews == null) {
                view.message("A fazer primeiro preenchimento de GestReviews...");
                this.gestReviews = new GestReviews();
                this.gestReviews.readFromFiles(UsersFile, BusinessesFile, ReviewsFile);
            }
            Crono.start();
            this.gestReviews.query10();
            return Crono.stop();

        } catch (IOException e) {
            view.message(e.getMessage());
        }
        return 0;
    }

    public void MainMenu() {
        view.menuTestes();

        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();

        switch (option) {
            case 1:
                LeituraFicheirosCSVM();
                break;
            case 2:
                EscritaELeituraObjetos();
                break;
            case 3:
                Queries();
            default:
                break;
        }
    }

    public void LeituraFicheirosCSVM() {
        view.menuLeituraFicheirosCSV();
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();

        switch (option) {
            case 1:
                ImprimirResultadoTeste("Todos os ficheiro", LeituraFicheirosCSV());
                break;
            case 2:
                ImprimirResultadoTeste("Ficheiro Users", LeituraFicheirosUsersCSV());
                break;
            case 3:
                ImprimirResultadoTeste("Ficheiro Businesses", LeituraFicheirosBusinessesCSV());
                break;
            case 4:
                ImprimirResultadoTeste("Ficheiro Reviews", LeituraFicheirosReviewsCSV());
                break;
            default:
                MainMenu();

                break;
        }
    }

    void EscritaELeituraObjetos() {
        view.menuEscritaLeituraObjetos();
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();

        switch (option) {
            case 1:
                ImprimirResultadoTeste("Escrita de GestReviews em ficheiro", EscritaEmFicheiroGestReview());
                break;
            case 2:
                view.message("1) Insirir caminho para ficheiro de objetos \n2) Usar o ficheiro gerado no teste anterior");
                int option2 = scanner.nextInt();
                String filePath = ObjectFile;
                if (option2 == 1) {
                    filePath = scanner.nextLine();
                }
                File objetfile = new File(filePath);
                if (!objetfile.exists()) {
                    view.message("Ficheiro nao existe!");
                    EscritaELeituraObjetos();
                } else {
                    ImprimirResultadoTeste("Leitura de GestReviews em ficheiro", LeituraparaMemoriaFicheiroGestReview(filePath));
                }
                break;
            default:
                MainMenu();
                break;
        }
    }

    public void Queries() {
        view.menuQueries();

        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();

        switch (option) {
            case 1:
                ImprimirResultadoTeste("Query 1", Query1());
                break;
            case 2:
                ImprimirResultadoTeste("Query 2", Query2());
                break;
            case 3:
                ImprimirResultadoTeste("Query 3", Query3());
                break;
            case 4:
                ImprimirResultadoTeste("Query 4", Query4());
                break;
            case 5:
                ImprimirResultadoTeste("Query 5", Query5());
                break;
            case 6:
                ImprimirResultadoTeste("Query 6", Query6());
                break;
            case 7:
                ImprimirResultadoTeste("Query 7", Query7());
                break;
            case 8:
                ImprimirResultadoTeste("Query 8", Query8());
                break;
            case 9:
                ImprimirResultadoTeste("Query 9", Query9());
                break;
            case 10:
                ImprimirResultadoTeste("Query 10", Query10());
                break;
            default:
                MainMenu();
                break;
        }
    }

    public void ImprimirResultadoTeste(String mensagem, double valor) {
        view.message("Resultado de " + mensagem + "---->  " + valor + " s");
        view.message("\n Prima 0 para voltar ao menu principal");
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        MainMenu();
    }

    public boolean UsarValoresInput() {
        view.message("Deseja usar valores especificos (1) ou nao (2)?");
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        if (option == 1) return true;
        else return false;
    }
}
