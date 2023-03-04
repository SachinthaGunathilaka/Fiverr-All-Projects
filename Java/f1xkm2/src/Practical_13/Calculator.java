package Practical_13;

import java.util.Objects;

public class Calculator {
    Stack stack;

    public Calculator() {
        stack = new Stack();
    }



    public void push(String element) {
        stack.push(element);

        String method = "push(" + element + ")";
        String return_val = element;
        StringBuilder contents = stack.getContent();

        System.out.printf("| %-15s | %-20s | %-20s |\n", method, return_val, contents);
        System.out.println("+---------------------------------------------------------------+");

    }

    public String pop() {
        String method = "pop()";
        String return_val = stack.pop();
        StringBuilder contents = stack.getContent();

        System.out.printf("| %-15s | %-20s | %-20s |\n", method, return_val, contents);
        System.out.println("+---------------------------------------------------------------+");


        return return_val;
    }

    public void calculate(String expression) {
        System.out.println("+---------------------------------------------------------------+");
        System.out.printf("| %-15s | %-20s | %-20s |\n", "Method", "Return Value", "Stack Contents");
        System.out.println("+---------------------------------------------------------------+");

        String[] elements = expression.split(" ");

        for (String element : elements) {
            push(element);

            if (Objects.equals(element, "+")) {
                pop();
                double value2 = Double.parseDouble(pop());
                double value1 = Double.parseDouble(pop());

                push(String.valueOf(value1 + value2));
            } else if (Objects.equals(element, "-")) {
                pop();

                double value2 = Double.parseDouble(pop());
                double value1 = Double.parseDouble(pop());

                push(String.valueOf(value1 - value2));

            } else if (Objects.equals(element, "*")) {
                pop();

                double value2 = Double.parseDouble(pop());
                double value1 = Double.parseDouble(pop());

                push(String.valueOf(value1 * value2));
            } else if (Objects.equals(element, "/")) {
                pop();

                double value2 = Double.parseDouble(pop());
                double value1 = Double.parseDouble(pop());

                push(String.valueOf(value1 / value2));
            }


        }


    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        String expression = "4 5 + 1 2 * - 5 /";
        calculator.calculate(expression);


    }
}
