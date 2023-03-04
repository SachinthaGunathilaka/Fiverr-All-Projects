import java.util.Objects;
import java.util.Scanner;
import java.util.LinkedList;

public class ShoppingList {
   public static void main (String[] args) {
      Scanner scnr = new Scanner(System.in);

      // TODO: Declare a LinkedList called shoppingList of type ListItem
      LinkedList<ListItem> shoppingList = new LinkedList<>();

      String item;
      
      // TODO: Scan inputs (items) and add them to the shoppingList LinkedList
      //       Read inputs until a -1 is input
      String input = scnr.nextLine().strip();
      while (!Objects.equals(input, "-1")){
         ListItem listItem = new ListItem(input);
         shoppingList.add(listItem);
         input = scnr.nextLine().strip();

      }
     
      
      // TODO: Print the shoppingList LinkedList using the printNodeData() method
      for (ListItem listItem:shoppingList) {
         listItem.printNodeData();
      }

   }
}