package Extra;

import Model.IUser;

public class Query9Pair implements Comparable<Query9Pair> {
    private IUser user;
    private float grade;

    public Query9Pair(IUser user, float grade) {
        this.user = user;
        this.grade = grade;
    }

    public IUser getUser() {
        return user;
    }

    public float getGrade() {
        return grade;
    }

    public int compareTo(Query9Pair qp) {
        if (Float.compare(this.grade, qp.getGrade()) == 0) return this.user.getName().compareTo(qp.getUser().getName());
        else return (int) (qp.getGrade() - this.grade);
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();

        sb.append("{User name: ");
        sb.append(this.user.getName() + "\n");
        sb.append("Grade: ");
        sb.append(this.grade + "}\n");

        return sb.toString();
    }
}
