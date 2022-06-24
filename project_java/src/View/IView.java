package View;

import Extra.*;
import Model.IBusiness;

import java.util.*;

public interface IView {
    void menu();
    void menuQueries();
    void menuEstatisticas();
    void menuTestes();
    void menuLeituraFicheirosCSV();
    void menuEscritaLeituraObjetos();
    void dadosEstatisticosFicheiros(List<String> ultimosFicheirosLidos, int reviewsErradas, int totalNegocios, int totalDifNegociosAv, int negociosNaoAvaliados, int totalUsers, int usersComReviews, int usersSemReviews, int reviewsZeroImpacto);
    void dadosEstatisticosGerais(Map<Integer,Integer> reviewsPorMes, Map<Integer,Float> mediaPorMes, float mediaGlobal, Map<Integer, Integer> UsersPorMes);
    void rodape();
    void showquery1(Set<String> res, int page, int pageSize);
    void showquery2(Query2 res, int mes, int ano);
    void showquery3(Integer month, Query3Triple res);
    void showquery4(Integer month, RatingBusiness res);
    void showquery5(Set<Query5Pair> res, int page, int pageSize);
    void showquery6(int ano, TreeSet<RatingBusiness> bus, int page, int pageSize);
    void showquery7(String city, List<IBusiness> businesses);
    void showquery8(TreeMap<Integer,String> res, int x, int page, int pageSize);
    void showquery9(Set<Query9Pair> res, int page, int pageSize);
    void showquery10(String estado, String city,  Map<String,RatingBusiness> bus , int page, int pageSize);
    void message(String msg);
}
