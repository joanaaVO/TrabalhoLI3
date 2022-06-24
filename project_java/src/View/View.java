package View;

import Extra.*;
import Model.IBusiness;
import Model.Reviews;

import java.time.Month;
import java.util.*;

/**
 * Classe que apresenta ao utilizador informações relevantes sobre a aplicacação tal como menus, pedidos e erros.
 */

public class View implements IView {

    public void menu() {
        System.out.println("***************************MENU PRINCIPAL******************************");
        System.out.println("1- Leitura de ficheiros");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Gravar dados");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("3- Carregar dados");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("4- Estatísticas");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("5- Queries");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Sair");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void menuQueries() {
        System.out.println("****************************MENU QUERIES*******************************");
        System.out.println("1- Query 1");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Query 2");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("3- Query 3");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("4- Query 4");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("5- Query 5");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("6- Query 6");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("7- Query 7");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("8- Query 8");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("9- Query 9");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("10- Query 10");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Sair");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void menuEstatisticas() {
        System.out.println("****************************ESTATÍSTICAS*******************************");
        System.out.println("1- Ficheiros");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Gerais");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Sair");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void menuTestes() {
        System.out.println("*****************************MENU TESTES********************************");
        System.out.println("1- Testar leitura ficheiros CSV");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Testar escrita e leitura de ficheiro de objetos");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("3- Queries");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Sair");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void menuLeituraFicheirosCSV() {
        System.out.println("***************************MENU TESTES CSV******************************");
        System.out.println("1- Testar toda leitura ficheiros CSV");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Testar leitura de Users");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("3- Testar leitura de Businesses");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("4- Testar leitura de Reviews");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Voltar");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void menuEscritaLeituraObjetos() {
        System.out.println("******************MENU TESTES ESCRITA/LEITURA OBJETOS*******************");
        System.out.println("1- Testar Escrita de GestReviews em ficheiro");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("2- Testar leitura de GestReviews em ficheiro");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("0- Voltar");
        System.out.println("───────────────────────────────────────────────────────────────────────");
        System.out.println("Opção: ");
    }

    public void dadosEstatisticosFicheiros(List<String> ultimosFicheirosLidos, int reviewsErradas, int totalNegocios, int totalDifNegociosAv, int negociosNaoAvaliados, int totalUsers, int usersComReviews, int usersSemReviews, int reviewsZeroImpacto) {
        System.out.println("Últimos ficheiros: ");
        System.out.println("Users-> " + ultimosFicheirosLidos.get(0));
        System.out.println("Businesses-> " + ultimosFicheirosLidos.get(1));
        System.out.println("Reviews-> " + ultimosFicheirosLidos.get(2));
        System.out.println("Número total de reviews erradas: " + reviewsErradas);
        System.out.println("Número total de negócios: " + totalNegocios);
        System.out.println("Total de diferentes negócios avaliados: " + totalDifNegociosAv);
        System.out.println("Total de negócios não avaliados: " + negociosNaoAvaliados);
        System.out.println("Número total de users: " + totalUsers);
        System.out.println("Número de users que fizeram reviews: " + usersComReviews);
        System.out.println("Total de users que nada avaliaram: " + usersSemReviews);
        System.out.println("Total de reviews com zero impacto: " + reviewsZeroImpacto);
    }

    public void dadosEstatisticosGerais(Map<Integer,Integer> reviewsPorMes, Map<Integer,Float> mediaPorMes, float mediaGlobal, Map<Integer, Integer> usersPorMes) {
        System.out.println("Número total de reviews por mês: ");
        for(Integer month : reviewsPorMes.keySet()) {
            System.out.println(Month.of(month) + ": " + reviewsPorMes.get(month));
        }
        System.out.println("Média de classificação de reviews por mês: ");
        for(Integer month : mediaPorMes.keySet()) {
            System.out.println(Month.of(month) + ": " + mediaPorMes.get(month));
        }
        System.out.println("Média global de reviews: " + mediaGlobal);
        System.out.println("Número de distintos utilizadores que avaliaram em cada mês: ");
        for(Integer month : usersPorMes.keySet()) {
            System.out.println(Month.of(month) + ": " + usersPorMes.get(month));
        }
    }

    public void rodape() {
        System.out.println("(1) PÁGINA ANTERIOR                   (2) PÁGINA SEGUINTE                   (0) SAIR");
        System.out.println();
        System.out.println("OPÇÃO: ");
    }

    public void showquery1(Set<String> res, int page, int pageSize) {
        int first = (page-1)*pageSize;
        String[] bus = res.toArray(new String[res.size()]);
        System.out.println("TOTAL: " + res.size());
        System.out.println("─────────────────────────────────────");
        System.out.println("CÓDIGO DO NEGÓCIO");
        for(int i=first; i < (pageSize*page)-1 && bus[i] != null; i++) {
            System.out.println(bus[i]);
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void showquery2(Query2 res, int mes, int ano) {
        System.out.println("MÊS: " + mes + " | ANO: " + ano);
        System.out.println("───────────────────────────────────────────────");
        System.out.println("NÚMERO TOTAL DE REVIEWS: " + res.getTotalReviews());
        System.out.println("NÚMERO TOTAL DE USERS DISTINTOS: " + res.getTotalUsersUnique());
        System.out.println("───────────────────────────────────────────────");
        System.out.println("Prima ENTER para continuar...");
    }

    public void showquery3(Integer month, Query3Triple res) {
        System.out.println("MÊS: " + month);
        System.out.println("───────────────────────────────────────────────");
        System.out.println("REVIEWS: " + res.getNumberOfReviews());
        System.out.println("NEGÓCIOS DISTINTOS AVALIADOS: " + res.getBusinessesReviewed());
        System.out.println("NOTA MÉDIA: " + res.getAverageGrade());
        System.out.println("───────────────────────────────────────────────");
        System.out.println("Prima ENTER para continuar...");
    }

    public void showquery4(Integer month, RatingBusiness res) {
        System.out.println("MÊS: " + month);
        System.out.println("───────────────────────────────────────────────");
        System.out.println("NÚMERO DE VEZES AVALIADO: " + res.getTotalReviews());
        System.out.println("UTILIZADORES DISTINTOS QUE O AVALIARAM: " + res.getTotalUniqueUsers());
        System.out.println("CLASSIFICAÇÃO MÉDIA: " + res.getMediaAvaliacao());
        System.out.println("───────────────────────────────────────────────");
        System.out.println("Prima ENTER para continuar...");
    }

    public void showquery5(Set<Query5Pair> res, int page, int pageSize) {
        int first = (page-1)*pageSize;
        Query5Pair[] aux = res.toArray(new Query5Pair[res.size()]);
        for(int i=first; i < (pageSize*page)-1 && aux[i] != null; i++) {
            System.out.println("NOME: " + aux[i].getName());
            System.out.println("NÚMERO: " + aux[i].getNumber());
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void showquery6(int ano, TreeSet<RatingBusiness> bus, int page, int pageSize) {
        int first = (page-1)*pageSize;
        RatingBusiness[] aux = bus.toArray(new RatingBusiness[bus.size()]);
        System.out.println("ANO: " + ano);
        System.out.println("─────────────────────────────────────");
        for(int i=first; i < (pageSize*page)-1 && i< bus.size(); i++) {
            System.out.println("NEGÓCIO: " + aux[i].getBusinessId()); //estão a imprimar null
            System.out.println("UTILIZADORES DISTINTOS QUE O AVALIARAM: " + aux[i].getTotalUniqueUsers());
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void showquery7(String city, List<IBusiness> businesses) {
        System.out.println();
        System.out.println("CIDADE: " + city);
        System.out.println("─────────────────────────────────────");
        for(IBusiness bus : businesses) {
            System.out.println("NOME DO NEGÓCIO: " + bus.getName());
        }
        System.out.println("Prima qualquer número para continuar (0 para sair)...");
    }

    public void showquery8(TreeMap<Integer,String> res, int x, int page, int pageSize) {
        int first = (page-1)*pageSize;
        Integer[] aux = res.keySet().toArray(new Integer[x]);
        for(int i=first; i < (pageSize*page)-1 && i<x; i++) {
            System.out.println("USER: " + res.get(aux[i]));
            System.out.println("NEGÓCIOS AVALIADOS: " + aux[i]);
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void showquery9(Set<Query9Pair> res, int page, int pageSize) {
        int first = (page-1)*pageSize;
        Query9Pair[] aux = res.toArray(new Query9Pair[res.size()]);
        for(int i=first; i < (pageSize*page)-1 && aux[i] != null; i++) {
            System.out.println("USER: " + aux[i].getUser().getName());
            System.out.println("CLASSIFICAÇÃO MÉDIA: " + aux[i].getGrade());
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void showquery10(String estado, String city,  Map<String,RatingBusiness> bus , int page, int pageSize) {
        int first = (page-1)*pageSize;
        String[] aux = bus.keySet().toArray(new String[0]);
        System.out.println("ESTADO: " + estado + " | CIDADE: " + city);
        System.out.println("─────────────────────────────────────");
        for(int i=first; i < (pageSize*page)-1 && i < bus.size(); i++) {
            System.out.println("NEGÓCIO: " + aux[i]);
            System.out.println("CLASSIFICAÇÃO MÉDIA: " + bus.get(aux[i]).getMediaAvaliacao());
            System.out.println("─────────────────────────────────────");
        }
        this.rodape();
    }

    public void message(String msg) {
        System.out.println(msg);
    }
}
