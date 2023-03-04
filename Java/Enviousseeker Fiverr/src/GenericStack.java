import java.util.ArrayList;

public class GenericStack<E> {
    private ArrayList<E> list;

    public GenericStack() {
        list = new ArrayList<>();
    }

    public int getSize() {
        return list.size();
    }

    public boolean isEmpty() {
        return list.size() == 0;
    }

    public E peek() {
        return list.get(list.size() - 1);
    }

    public void push(E value) {
        list.add(value);
    }

    public E pop() {
        E top_val = list.get(list.size() - 1);
        list.remove(list.size() - 1);
        return top_val;
    }




}


