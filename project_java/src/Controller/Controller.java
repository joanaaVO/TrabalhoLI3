package Controller;

import Extra.*;
import Model.IBusiness;
import Model.IGestReviews;
import View.IView;

import java.io.*;
import java.util.*;

/**
 * Classe responsável pela interação com o utilizador.
 */
public class Controller implements IController {
    private IGestReviews model;
    private IView view;

    public Controller(IGestReviews model, IView view) {
        this.model = model;
        this.view = view;
    }

    /**
     * Método que apresenta ao utilizador o menu principal.
     * Permite ler ficheiros, guardar e carregar dados, consultar estatísticas e queries.
     */

    public void run() {
        view.menu();
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        scanner.nextLine();

        switch (option) {
            case 1:
                this.readFiles();
                System.out.println("Prima ENTER para continuar...");
                scanner.nextLine();
                this.run();
                break;

            case 2:
                this.WriteGestReview();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.run();
                break;

            case 3:
                this.ReadGestReview();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.run();
                break;

            case 4:
                if (!this.model.getUltimosFicheirosLidos().isEmpty()) this.estatisticas();
                else {
                    view.message("Nenhum ficheiro lido anteriormente!");
                    view.message("Prima ENTER para continuar...");
                    scanner.nextLine();
                }
                this.run();
                break;

            case 5:
                if (!this.model.getUltimosFicheirosLidos().isEmpty()) this.queries();
                else {
                    view.message("Nenhum ficheiro lido anteriormente!");
                    view.message("Prima ENTER para continuar...");
                    scanner.nextLine();
                }
                this.run();
                break;

            case 0:
                break;

            default:
                view.message("Opção inválida!");
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.run();
                break;
        }
    }

    /**
     * Método que lê, caso sejam fornecido, o ficheiros relativos às estruturas.
     * Caso contrário, lê o ficheiro definido por default.
     */
    public void readFiles() {
        String users, businesses, reviews;
        Scanner input = new Scanner(System.in);

        view.message("Insira o ficheiro dos users ou prima ENTER para usar o default: ");
        users = input.nextLine();
        view.message("Insira o ficheiro dos businesses ou prima ENTER para usar o default: ");
        businesses = input.nextLine();
        view.message("Insira o ficheiro das reviews ou prima ENTER para usar o default: ");
        reviews = input.nextLine();

        if (users.isEmpty()) users = "src/Extra/Ficheiros/users_full.csv";
        if (businesses.isEmpty()) businesses = "src/Extra/Ficheiros/business_full.csv";
        if (reviews.isEmpty()) reviews = "src/Extra/Ficheiros/reviews_1M.csv";

        view.message("A ler ficheiros....");
        try {
            this.model.readFromFiles(users, businesses, reviews);
        } catch (IOException e) {
            view.message(e.getMessage());
        }
    }

    /**
     * Método que guarda em ficheiro o estado da aplicação.
     */
    public void WriteGestReview() {
        view.message("Insira o nome do ficheiro onde quer guardar o estado ou prima ENTER para usar o default: ");
        Scanner scanner = new Scanner(System.in);
        String path;
        path = scanner.nextLine();
        if(path.isEmpty()) path = "src/Extra/Ficheiros/gestReviews.dat";
        view.message("Gravando estado atual do GestReviews...");
        WriteReadGestReviews.WriteGestReview(path, this.model);
    }

    /**
     * Método que lê de um ficheiro de objetos um estado guardado da aplicação.
     */
    public void ReadGestReview() {
        view.message("Insira o nome do ficheiro onde guardou o estado da aplicação ou prima ENTER para usar o default:");
        Scanner scanner = new Scanner(System.in);
        String path;
        path = scanner.nextLine();
        if(path.isEmpty()) path = "src/Extra/Ficheiros/gestReviews.dat";
        view.message("Lendo estado do GestReviews...");

        this.model = WriteReadGestReviews.ReadGestReview(path);
    }

    /**
     * Método que permite consultar estatísticas gerais e de ficheiro.
     */
    public void estatisticas() {
        view.menuEstatisticas();
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        scanner.nextLine();

        switch (option) {
            case 1:
                view.dadosEstatisticosFicheiros(model.getUltimosFicheirosLidos(), model.getReviewsErradas(), model.getTotalNegocios(), model.getTotalNegocios()- model.query1().size(), model.query1().size(), model.numOfUsers(), model.numOfUsersWithReviews(), model.numOfUsers()- model.numOfUsersWithReviews(), model.reviewsZeroImpacto());
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.estatisticas();
                break;

            case 2:
                view.dadosEstatisticosGerais(model.totalReviewsByMonth(), model.averageReviewsGradeByMonth(), model.globalReviewsGrade(), model.usersReviewedByMonth());
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.estatisticas();
                break;

            case 0:
                break;

            default:
                view.message("Opção inválida!");
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                this.estatisticas();
                break;

        }
    }

    /**
     * Método que permite ao utilizador obter e solicitar resultados das queries.
     */
    public void queries() {
        view.menuQueries();
        Scanner scanner = new Scanner(System.in);
        int option = scanner.nextInt();
        scanner.nextLine();

        switch (option) {
            case 1:
                Crono.start();
                Set<String> query1 = model.query1();
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                int page = 1;
                int pageSize = 30;
                while (true) {
                    view.showquery1(query1, page, pageSize);
                    int opt = scanner.nextInt();
                    if (opt == 1) {
                        if (page > 1) page--;
                    } else if (opt == 2) {
                        if (page * pageSize < query1.size()) page++;
                    } else if (opt == 0) break;
                }
                this.queries();
                break;

            case 2:
                view.message("Insira um mês (1-12): ");
                int month = scanner.nextInt();
                scanner.nextLine();
                while (month < 1 || month > 12) {
                    view.message("Mês Inválido! Tente novamente: ");
                    month = scanner.nextInt();
                    scanner.nextLine();
                }
                int year = scanner.nextInt();
                scanner.nextLine();
                view.message("Insira um ano: ");
                while (year < 2004 || year > 2021) {
                    view.message("Ano Inválido! Tente novamente: ");
                    month = scanner.nextInt();
                    scanner.nextLine();
                }
                Crono.start();
                Query2 query2 = model.query2(month, year);
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                view.showquery2(query2, month, year);
                scanner.nextLine();
                this.queries();
                break;

            case 3:
                view.message("Insira um código de utilizador: ");
                String user_id = scanner.nextLine();
                while (!this.model.existsUser(user_id)) {
                    view.message("Utilizador não existente! Tente novamente.");
                    user_id = scanner.nextLine();
                }
                Crono.start();
                Map<Integer, Query3Triple> query3 = model.query3(user_id); //("q_QQ5kBBwlCcbL1s4NVK3g");("RtGqdDBvvBCjcu5dUqwfzA");
                Crono.stop();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                while (true) {
                    for (Map.Entry<Integer, Query3Triple> m : query3.entrySet()) {
                        view.showquery3(m.getKey(), m.getValue());
                        scanner.nextLine();
                    }
                    break;
                }
                this.queries();
                break;

            case 4:
                view.message("Insira um código de negócio: ");
                String bus_id = scanner.nextLine();
                while (!this.model.existsBusiness(bus_id)) {
                    view.message("Negócio não existente! Tente novamente.");
                    bus_id = scanner.nextLine();
                }
                Crono.start();
                Query4 query4 = model.query4(bus_id); //"TwXlumHJTdCUjhEiuQkmeg"; "Fu0iAuNKsmjkmH1uJsjeHA"
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                TreeMap<Integer, RatingBusiness> ratings = query4.getRatings();
                while (true) {
                    for (Map.Entry<Integer, RatingBusiness> m : ratings.entrySet()) {
                        view.showquery4(m.getKey(), m.getValue());
                        scanner.nextLine();
                    }
                    break;
                }
                this.queries();
                break;

            case 5:
                view.message("Insira um código de utilizador: ");
                user_id = scanner.nextLine();
                while (!this.model.existsUser(user_id)) {
                    view.message("Utilizador não existente! Tente novamente.");
                    user_id = scanner.nextLine();
                }
                Crono.start();
                Set<Query5Pair> query5 = model.query5(user_id); //"RtGqdDBvvBCjcu5dUqwfzA";
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                page = 1;
                pageSize = 10;
                while (true) {
                    view.showquery5(query5, page, pageSize);
                    int opt = scanner.nextInt();
                    if (opt == 1) {
                        if (page > 1) page--;
                    } else if (opt == 2) {
                        if (page * pageSize < query5.size()) page++;
                    } else if (opt == 0) break;
                }
                this.queries();
                break;

            case 6:
                view.message("Insira o número de negócios: ");
                int num = scanner.nextInt();
                scanner.nextLine();
                Crono.start();
                Query6 query6 = model.query6(num);
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                TreeMap<Integer, TreeSet<RatingBusiness>> bus = query6.getBusinesPorAnoSortedByReviews();
                page = 1;
                pageSize = 10;
                while (true) {
                    for (Integer ano : bus.keySet()) {
                        int opt;
                        while (true) {
                            view.showquery6(ano, bus.get(ano), page, pageSize);
                            opt = scanner.nextInt();
                            if (opt == 1) {
                                if (page > 1) page--;
                            } else if (opt == 2) {
                                if (page * pageSize < num) page++; //fix no tamanho
                            } else if (opt == 0) break;
                        }
                        view.message("Prima qualquer número para consultar o próximo ano (0 para sair)...");
                        opt = scanner.nextInt();
                        if (opt == 0) break;
                    }
                    break;
                }
                this.queries();
                break;

            case 7:
                Crono.start();
                Map<String, List<IBusiness>> query7 = model.query7();
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                while (true) {
                    for (Map.Entry<String, List<IBusiness>> m : query7.entrySet()) {
                        view.showquery7(m.getKey(), m.getValue());
                        int opt = scanner.nextInt();
                        if (opt == 0) break;
                    }
                    break;
                }
                this.queries();
                break;

            case 8:
                view.message("Insira o número de utilizadores: ");
                int num_users = scanner.nextInt();
                scanner.nextLine();
                Crono.start();
                Query8 query8 = model.query8();
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                TreeMap<Integer, String> users = query8.get_users_com_mais_businesses();
                page = 1;
                pageSize = 10;
                while (true) {
                    view.showquery8(users, num_users, page, pageSize);
                    int opt = scanner.nextInt();
                    if (opt == 1) {
                        if (page > 1) page--;
                    } else if (opt == 2) {
                        if (page * pageSize < num_users) page++;
                    } else if (opt == 0) break;
                }
                this.queries();
                break;

            case 9:
                view.message("Insira um código de negócio: ");
                bus_id = scanner.nextLine();
                while (!this.model.existsBusiness(bus_id)) {
                    view.message("Negócio não existente! Tente novamente.");
                    bus_id = scanner.nextLine();
                }
                view.message("Insira o número de utilizadores");
                num_users = scanner.nextInt();
                scanner.nextLine();
                Crono.start();
                Set<Query9Pair> query9 = model.query9(bus_id, num_users); // "arEXRZYu8220bFBJ3VAh3A",100;
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                page = 1;
                pageSize = 10;
                while (true) {
                    view.showquery9(query9, page, pageSize);
                    int opt = scanner.nextInt();
                    if (opt == 1) {
                        if (page > 1) page--;
                    } else if (opt == 2) {
                        if (page * pageSize < query9.size()) page++;
                    } else if (opt == 0) break;
                }
                this.queries();
                break;

            case 10:
                Crono.start();
                Query10 query10 = model.query10();
                Crono.printElapsedTime();
                view.message("Prima ENTER para continuar...");
                scanner.nextLine();
                Map<String, Map<String, Map<String, RatingBusiness>>> busState = query10.getBusinesses_porState();
                while (true) {
                    for (Map.Entry<String, Map<String, Map<String, RatingBusiness>>> m1 : busState.entrySet()) {
                        int opt;
                        Map<String, Map<String, RatingBusiness>> m2 = m1.getValue();
                        for (String city : m2.keySet()) {
                            page = 1;
                            pageSize = 10;
                            for (String business : m2.get(city).keySet()) {
                                view.showquery10(m1.getKey(), city, m2.get(city), page, pageSize);
                                opt = scanner.nextInt();
                                if (opt == 1) {
                                    if (page > 1) page--;
                                } else if (opt == 2) {
                                    if (page * pageSize < m2.get(city).size()) page++;
                                } else if (opt == 0) break;
                            }
                            view.message("Prima qualquer número para consultar a próxima cidade (0 para sair)...");
                            opt = scanner.nextInt();
                            if (opt == 0) break;
                        }
                        view.message("Prima qualquer número para consultar o próximo estado (0 para sair)...");
                        opt = scanner.nextInt();
                        if (opt == 0) break;
                    }
                    break;
                }
                this.queries();
                break;

            case 0:
                break;

            default:
                view.message("Opção inválida!");
        }
    }
}
