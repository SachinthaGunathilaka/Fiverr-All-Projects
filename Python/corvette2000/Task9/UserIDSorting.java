import java.util.Scanner;
import java.util.ArrayList;

public class UserIDSorting {
    // TODO: Write the partitioning algorithm - pick the middle element as the
    //       pivot, compare the values using two index variables l and h (low and high),
    //       initialized to the left and right sides of the current elements being sorted,
    //       and determine if a swap is necessary
    public static int partition(ArrayList<String> userIDs, int i, int k) {
        String tmp;
        String pivot = userIDs.get((i + k) / 2);
        while (i <= k) {
            while (pivot.compareTo(userIDs.get(i)) > 0)
                i++;
            while (userIDs.get(k).compareTo(pivot) > 0)
                k--;
            if (i <= k) {
                tmp = userIDs.get(i);
                userIDs.set(i, userIDs.get(k));
                userIDs.set(k, tmp);
                i++;
                k--;
            }
        }
        return i;
    }

    // TODO: Write the quicksort algorithm that recursively sorts the low and
    //       high partitions
    public static void quicksort(ArrayList<String> userIDs, int i, int k) {
        int index = partition(userIDs, i, k);

        if (i < index - 1)
            quicksort(userIDs, i, index - 1);

        if (index < k)

            quicksort(userIDs, index, k);
    }

    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);

        ArrayList<String> userIDList = new ArrayList<String>();

        String userID;

        userID = scnr.next();
        while (!userID.equals("-1")) {
            userIDList.add(userID);
            userID = scnr.next();
        }

        // Initial call to quicksort
        quicksort(userIDList, 0, userIDList.size() - 1);

        for (int i = 0; i < userIDList.size(); ++i) {
            System.out.println(userIDList.get(i));
        }
    }
}

