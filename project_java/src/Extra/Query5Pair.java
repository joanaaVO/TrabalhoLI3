package Extra;

public class Query5Pair implements Comparable<Query5Pair> {
    private String name;
    private int number;

    public Query5Pair(String name, int number) {
        this.name = name;
        this.number = number;
    }

    public String getName() {
        return name;
    }

    public int getNumber() {
        return number;
    }

    public int compareTo(Query5Pair qp) {
        if(this.number == qp.getNumber()) return this.name.compareTo(qp.getName());
        else return qp.getNumber() - this.number;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();

        sb.append("{Business name: ");
        sb.append(this.name + "\n");
        sb.append("Number: ");
        sb.append(this.number + "}\n");

        return sb.toString();
    }
}
