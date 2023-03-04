import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Objects;
import java.util.Scanner;

class BST {
    //node class that defines BST node
    static class Node {
        String word;
        int count;
        Node left, right;

        public Node(String word) {
            this.word = word;
            this.count = 1;
            left = right = null;
        }
    }

    // BST root node
    Node root;

    // Constructor for BST =>initial empty tree
    BST() {
        root = null;
    }


    // Insert function
    void insert(String word) {
        // If the tree is empty
        if (root == null) {
            root = new Node(word); // set the root
            return;
        }

        Node temp = root; // temporary node

        // Do level order traversal until we find an empty place.
        while (true) {

            // If the word is equal to the current word
            if (word.equals(temp.word)) {
                temp.count++;
                break;
            }
            // If the word is alphabetically smaller than the current word
            else if (word.compareTo(temp.word) < 0) {
                // If the left child of temp is null set new node as the left child
                if (temp.left == null) {
                    temp.left = new Node(word);
                    break;
                }

                // If left child of temp is not null, set it as the next temp node
                else
                    temp = temp.left;

            }

            // If the key is larger than the current value
            else {
                // If the right child of temp is null set new node as the right child
                if (temp.right == null) {
                    temp.right = new Node(word);
                    break;
                }

                // If right child of temp is not null, set it as the next temp node
                else
                    temp = temp.right;

            }
        }
    }


    /* Inorder traversal of BST*/
    void inorder(Node temp) {
        if (temp == null)
            return;

        inorder(temp.left); // Go to Left node
        System.out.print(temp.word + " "); // Print current node value
        inorder(temp.right); // Go to right node
    }

    /* Preorder traversal of BST*/
    void preorder(Node temp) {
        if (temp == null)
            return;

        System.out.print(temp.word + " "); // Print current node value
        preorder(temp.left); // Go to Left node
        preorder(temp.right); // Go to right node
    }

    /* Postorder traversal of BST*/
    void postorder(Node temp) {
        if (temp == null)
            return;

        postorder(temp.left); // Go to Left node
        postorder(temp.right); // Go to right node
        System.out.print(temp.word + " "); // Print current node value
    }

    int getNumberOfWords(Node temp) {
        if (temp == null)
            return 0;

        int left_word_count = getNumberOfWords(temp.left);
        int right_word_count = getNumberOfWords(temp.right);

        return left_word_count + right_word_count + 1;

    }

    int getNumberOfUniqueWords(Node temp) {
        if (temp == null)
            return 0;

        int left_word_count = getNumberOfUniqueWords(temp.left);
        int right_word_count = getNumberOfUniqueWords(temp.right);

        if (temp.count == 1) {
            return left_word_count + right_word_count + 1;
        } else {
            return left_word_count + right_word_count;
        }
    }

    int getMostFrequentCount(Node temp) {
        if (temp == null)
            return 0;

        int l_count = getMostFrequentCount(temp.left);
        int r_count = getMostFrequentCount(temp.right);

        return Math.max(Math.max(l_count, r_count), temp.count);
    }

    void displayMostFrequentWords(Node temp, int count) {
        if (temp == null)
            return;

        displayMostFrequentWords(temp.left, count);
        displayMostFrequentWords(temp.right, count);

        if (temp.count == count) {
            System.out.println(temp.word + " = " + temp.count + " times");
        }
    }

    int maxDepth(Node node) {
        if (node == null) {
            return 0;
        }

        int lDepth = maxDepth(node.left);
        int rDepth = maxDepth(node.right);

        if (lDepth > rDepth)
            return lDepth + 1;
        else
            return rDepth + 1;
    }


    void searchWord(String word) {
        // If the tree is empty
        if (root == null) {
            System.out.println("Word not found!");
        }

        Node temp = root; // temporary node

        // Do level order traversal until we find an empty place.
        while (true) {

            // end of the traversal
            if (temp == null) {
                System.out.println("Word not found!");
                return;
            }

            // Find the word
            if (Objects.equals(word, temp.word)) {
                System.out.println("Found! It appears " + temp.count + " times in the input text file");
                return;
            }

            // traverse left
            if (word.compareTo(temp.word) < 0) {
                temp = temp.left;
            }
            // traverse right
            else {
                temp = temp.right;
            }
        }
    }
}

class Main {

    public static BST createBST(String filename) {
        try {
            BST bst = new BST();

            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine();
                String[] words = line.replaceAll("[^0-9a-zA-Z -]", "").toLowerCase().split("-|\\s+");

                for (String word : words) {
                    if(word.length() == 0)
                        continue;
                    bst.insert(word);
                }
            }
            myReader.close();
            return bst;
        } catch (FileNotFoundException e) {
            System.out.println("File does not exists!");
            return null;
        }

    }

    public static void DisplayMenu() {
        System.out.println("\n1) Change Input File\n" +
                "2) Display information of the BST\n" +
                "3) Search Word\n" +
                "4) Display BST\n" +
                "5) Quit");
    }

    public static int getOption(int options) {
        System.out.print("\nEnter option : ");
        Scanner scanner = new Scanner(System.in);

        int option = Integer.parseInt(scanner.nextLine());
        while (option < 1 || option > options) {
            System.out.println("Invalid option!");
            System.out.print("Enter option again : ");
            option = Integer.parseInt(scanner.nextLine());
        }

        return option;
    }

    public static void main(String[] args) {
        System.out.println("\n---- Binary Search Tree ----");
        Scanner scanner = new Scanner(System.in);

        System.out.print("\nEnter the input filename : ");
        String filename = scanner.nextLine();
        BST bst = createBST(filename);
        while (bst == null) {
            System.out.print("\nEnter the input filename again : ");
            filename = scanner.nextLine();
            bst = createBST(filename);
        }

        while (true) {

            DisplayMenu();
            int option = getOption(5);

            if (option == 1) {
                System.out.print("\nEnter the input filename : ");
                filename = scanner.nextLine();
                bst = createBST(filename);
                while (bst == null) {
                    System.out.print("\nEnter the input filename again : ");
                    filename = scanner.nextLine();
                    bst = createBST(filename);
                }
            } else if (option == 2) {
                System.out.println("\nTotal number of words in " + filename.split("\\.")[0] + " = " + bst.getNumberOfWords(bst.root));
                System.out.println("Number of unique words in " + filename.split("\\.")[0] + " = " + bst.getNumberOfUniqueWords(bst.root));
                System.out.println("The word(s) which occur(s) most often and the number of times that it/they occur(s) = ");
                int max_count = bst.getMostFrequentCount(bst.root);
                bst.displayMostFrequentWords(bst.root, max_count);

                System.out.println("The maximum height of the tree = " + bst.maxDepth(bst.root));
            } else if (option == 3) {
                System.out.print("\nEnter the word you are looking for in " + filename.split("\\.")[0] + " ? ");
                String search_word = scanner.nextLine().toLowerCase(Locale.ROOT);
                bst.searchWord(search_word);
            } else if (option == 4) {
                System.out.print("\nEnter the BST traversal method (1 = IN-ORDER, 2 = PRE-ORDER, 3 = POST-ORDER) for " + filename.split("\\.")[0] + " ? ");
                int traversal_method = Integer.parseInt(scanner.nextLine());

                if (traversal_method == 1) {
                    bst.inorder(bst.root);
                    System.out.println();
                } else if (traversal_method == 2) {
                    bst.preorder(bst.root);
                    System.out.println();
                } else if (traversal_method == 3) {
                    bst.postorder(bst.root);
                    System.out.println();
                } else {
                    System.out.println("Invalid option!");
                }

            } else {
                break;
            }
        }

    }
}