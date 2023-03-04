import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String integerFile = "numbersSpring.txt";
        GenericStack<Integer> genericStack = new GenericStack<>();

        try (BufferedReader br = new BufferedReader(new FileReader(integerFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                int number = Integer.parseInt(line.trim());
                genericStack.push(number);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("\nValues read from file and pushed onto number stack:");
        System.out.println("---------------------------------------------------");
        printStack(genericStack);


        sortStack(genericStack);
        System.out.println("\nNumber Stack sorted - smallest to highest:");
        System.out.println("--------------------------------------------------");
        printStack(genericStack);

        int valueToReplace, replacementValue;
        System.out.print("\nEnter value to replace on integer stack: ");
        valueToReplace = Integer.parseInt(scanner.nextLine());

        System.out.print("Enter replacement value: ");
        replacementValue = Integer.parseInt(scanner.nextLine());

        searchAndReplace(genericStack, valueToReplace, replacementValue);
        System.out.println("\nNumber Stack - replaced " + valueToReplace + " with " + replacementValue);
        System.out.println("--------------------------------------");
        printStack(genericStack);


        String stringFile = "stringsSpring.txt";
        GenericStack<String> genericStack2 = new GenericStack<>();

        try (BufferedReader br = new BufferedReader(new FileReader(stringFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                genericStack2.push(line.trim());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("\n\nValues read from file and pushed onto string Stack:");
        System.out.println("-------------------------------------------------------");
        printStack(genericStack2);

        System.out.println("\nString Stack sorted - alphabetical order:");
        System.out.println("----------------------------------------------");
        sortStack(genericStack2);
        printStack(genericStack2);

        String valueToReplaceStr, replacementValueStr;
        System.out.print("\nEnter value to replace on string stack: ");
        valueToReplaceStr = scanner.nextLine();

        System.out.print("Enter replacement value: ");
        replacementValueStr = scanner.nextLine();
        searchAndReplace(genericStack2, valueToReplaceStr, replacementValueStr);
        System.out.println("\nString Stack - replaced " + valueToReplaceStr + " with " + replacementValueStr);
        System.out.println("-------------------------------------------------");
        printStack(genericStack2);
    }

    public static <E> void printStack(GenericStack<E> genericStack) {
        GenericStack<E> tempStack = new GenericStack<>();
        while (!genericStack.isEmpty()) {
            E value = genericStack.pop();
            System.out.println(value);
            tempStack.push(value);
        }

        while (!tempStack.isEmpty()) {
            genericStack.push(tempStack.pop());
        }


    }

    public static <E extends Comparable<E>> void sortStack(GenericStack<E> stack) {
        GenericStack<E> tempStack = new GenericStack<>();
        while (!stack.isEmpty()) {
            E minValue = removeSmallestElement(stack);
            tempStack.push(minValue);
        }

        while (!tempStack.isEmpty()) {
            stack.push(tempStack.pop());
        }
    }

    public static <E> boolean searchAndReplace(GenericStack<E> stack, E valueToReplace, E replacementValue) {
        GenericStack<E> tempStack = new GenericStack<>();
        boolean found = false;

        while (!stack.isEmpty()) {
            E value = stack.pop();

            if (value.equals(valueToReplace)) {
                value = replacementValue;
                found = true;
            }

            tempStack.push(value);
        }

        while (!tempStack.isEmpty()) {
            stack.push(tempStack.pop());
        }

        return found;
    }

    public static <E extends Comparable<E>> E removeSmallestElement(GenericStack<E> stack) {
        GenericStack<E> tempStack = new GenericStack<>();
        E value = stack.pop();
        E minValue = value;
        tempStack.push(value);

        while (!stack.isEmpty()) {
            value = stack.pop();
            tempStack.push(value);
            if (value.compareTo(minValue) < 0) {
                minValue = value;
            }
        }
        while (!tempStack.isEmpty()) {
            value = tempStack.pop();
            if (value != minValue)
                stack.push(value);
        }

        return minValue;
    }
}
