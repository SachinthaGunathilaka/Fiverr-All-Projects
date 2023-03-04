package Practical_13;

public class Stack {

    private int size;
    private int max_size;
    private String[] elements;


    Stack() {
        max_size = 10;
        size = 0;
        elements = new String[max_size];
    }


    void push(String value) {

        if (size == max_size) {
            max_size = max_size * 2;
            String[] new_elements = new String[max_size];
            for (int i = 0; i < size; i++) {
                new_elements[i] = elements[i];
            }
            elements = new_elements;
        }

        elements[size++] = value;

    }


    String pop() {
        if (size == 0)
            return null;

        size--;
        String top = elements[size];
        elements[size] = null;
        return top;
    }

    public StringBuilder getContent() {
        StringBuilder contents = new StringBuilder("(");

        for (int i = 0; i < size; i++) {
            if (i == size - 1)
                contents.append(elements[i]);

            else
                contents.append(elements[i] + ",");
        }

        contents.append(")");

        return contents;
    }

}
