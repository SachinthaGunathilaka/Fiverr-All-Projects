import java.util.*;

public class Main {

    public static void displayItems(ArrayList<String> items) {
        System.out.println();
        for (int i = 0; i < items.size(); i++) {
            if (i != 0 && i % 3 == 0)
                System.out.println();

            String text = (char) ('a' + i) + ") " + items.get(i);
            System.out.printf("%-35s", text);

            if (i == items.size() - 1)
                System.out.println();
        }
    }

    public static int getOption(String msg, int count) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("\n" + msg + ": ");
        int option = scanner.nextLine().charAt(0);

        while (option < 'a' || option > (char) ('a' + count - 1)) {
            System.out.println("Invalid option");
            System.out.print(msg + ": ");
            option = scanner.nextLine().charAt(0);
        }

        return option - 'a';
    }

    public static void main(String[] args) {
        int all_ings = 2;
        Map<String, String> selected_ingredients = new HashMap<String, String>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n************************************************");

        ArrayList<String> crust_items = new ArrayList<String>(Arrays.asList("regular crust", "gluten-free crust"));
        System.out.println("Please choose one crust option:");
        displayItems(crust_items);

        int crust_option = getOption("Enter choice", 2);

        System.out.println("* You chose:\t\t" + (char) ('a' + crust_option) + ". " + crust_items.get(crust_option) + " = 1 *");
        selected_ingredients.put(crust_items.get(crust_option), "1");
        System.out.println("\n************************************************");

        System.out.println("\nPlease choose one sauce option:");
        ArrayList<String> sauce_options = new ArrayList<String>(Arrays.asList("red sauce", "no red sauce"));
        displayItems(sauce_options);
        int sauce_option = getOption("Enter choice", 2);

         System.out.println("\nPlease chose one amount:");
        ArrayList<String> sauce_amounts = new ArrayList<String>(Arrays.asList("1/4 cup", "1/2 cup"));
        displayItems(sauce_amounts);
        int sauce_amount = getOption("Enter choice", 2);

        System.out.println("* You chose:\t\t" + (char) ('a' + sauce_option) + ". " + sauce_options.get(sauce_option) + " = " + sauce_amounts.get(sauce_amount) + " *");
        selected_ingredients.put(sauce_options.get(sauce_option), sauce_amounts.get(sauce_amount));

        System.out.println("\n************************************************");

        System.out.println("Please choose one ingredient option:");
        ArrayList<String> ingredients = new ArrayList<String>(Arrays.asList("pizza cheese", "diced onion", "diced green pepper",
                "pepperoni", "sliced mushroom", "diced jalapenos", "sardines", "pineapple chunks", "tofu", "ham chunks", "dry red pepper",
                "dry basil"));


        while (true){
            displayItems(ingredients);

            int ing_choice = getOption("Enter choice", ingredients.size());

            System.out.println("\nPlease chose one amount:");


            int amount;
            String amount_str = "";
            if (Objects.equals(ingredients.get(ing_choice), "pizza cheese") || Objects.equals(ingredients.get(ing_choice), "tofu")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("1/4 cup", "1/2 cup"));
                displayItems(amounts);
                amount = getOption("Enter choice", 2);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);
            } else if (Objects.equals(ingredients.get(ing_choice), "diced onion") || Objects.equals(ingredients.get(ing_choice), "diced green pepper") ||
                    Objects.equals(ingredients.get(ing_choice), "sliced mushroom") || Objects.equals(ingredients.get(ing_choice), "diced jalapenos")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("1/8 cup", "1/4 cup"));
                displayItems(amounts);
                amount = getOption("Enter choice", 4);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            } else if (Objects.equals(ingredients.get(ing_choice), "pepperoni") || Objects.equals(ingredients.get(ing_choice), "pineapple chunks")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("2 pieces", "4 pieces", "6 pieces", "8 pieces"));
                displayItems(amounts);
                amount = getOption("Enter choice", 4);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            } else if (Objects.equals(ingredients.get(ing_choice), "ham chunks")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("4 pieces", "8 pieces", "12 pieces", "16 pieces"));
                displayItems(amounts);
                amount = getOption("Enter choice", 4);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            } else if (Objects.equals(ingredients.get(ing_choice), "dry red pepper")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("1 generous sprinkle", "2 generous sprinkle"));
                displayItems(amounts);
                amount = getOption("Enter choice", 2);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            } else if (Objects.equals(ingredients.get(ing_choice), "dry basil")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("1 generous sprinkle", "2 generous sprinkle", "3 generous sprinkle", "4 generous sprinkle"));
                displayItems(amounts);
                amount = getOption("Enter choice", 4);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            } else if (Objects.equals(ingredients.get(ing_choice), "sardines")) {
                ArrayList<String> amounts = new ArrayList<String>(Arrays.asList("1 each", "2 each", "3 each", "4 each"));
                displayItems(amounts);
                amount = getOption("Enter choice", 4);
                selected_ingredients.put(ingredients.get(ing_choice), amounts.get(amount));
                amount_str = amounts.get(amount);

            }

            all_ings++;

            System.out.println("* You chose:\t\t" + (char) ('a' + ing_choice) + ". " + ingredients.get(ing_choice) + " = " + amount_str + " *");
            System.out.println("\n************************************************");

            ingredients.remove(ing_choice);

            System.out.println("\nWould you like to add another ingredient? ");

            System.out.printf("%-35s %-35s", "a. continue", "b. finished");
            System.out.println();

            if(all_ings == 8)
                break;

            int yes_no = getOption("Enter choice", 2);
            if(yes_no == 1)
                break;
        }

        System.out.println("\n************************************************");

        System.out.println("\n* Your pizza recipe *\n");

        for (var entry : selected_ingredients.entrySet()) {
            System.out.printf("%-35s %-35s\n", entry.getKey(), entry.getValue());
        }

        System.out.println("\n* Pizza is to be appropriately cooked until crust is cooked and toppings are warmed *");

        System.out.println("\n************************************************");




    }
}
