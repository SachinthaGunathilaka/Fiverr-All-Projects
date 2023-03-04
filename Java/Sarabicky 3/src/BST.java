
public class BinarySearchTree<E extends Comparable<E>> {
    @SuppressWarnings("unused")
    private static final long serialVersionUID = 29384723897L;

    class Node {
        E value;
        Node left = null;
        Node right = null;

        Node(E value) {
            this.value = value;
        }

        @Override
        public String toString() {
            return "( " + value + " )";
        }
    }

    protected Node root = null;
    protected int size = 0;

    public boolean add(E val) {
        if (val == null)
            return false;
        int size = this.size;
        this.root = add(this.root, val);
        return size != this.size;
    }

    private Node add(Node n, E val) {
        if (n == null) {
            this.size++;
            return new Node(val);
        }

        int cmp = val.compareTo(n.value);
        if (cmp < 0)
            n.left = add(n.left, val);
        else if (cmp > 0)
            n.right = add(n.right, val);
        return n;
    }

    public boolean remove(E val) {
        if (val == null)
            return false;
        int size = this.size;
        this.root = remove(this.root, val);
        return size != this.size;
    }

    private Node remove(Node n, E val) {
        if (n == null)
            return null;
        int cmp = val.compareTo(n.value);
        if (cmp < 0)
            n.left = remove(n.left, val);
        else if (cmp > 0)
            n.right = remove(n.right, val);
        else if (n.left == null) {
            /*
             * The value of n.right is the correct return value for this method whether it
             * is null or a Node. Thus there is no need for a (n.left == null && n.right ==
             * null) branch.
             */
            this.size--;
            return n.right;
        } else if (n.right == null) {
            this.size--;
            return n.left;
        } else {
            E pred = maxValue(n.left);
            n.value = pred;
            n.left = remove(n.left, pred);
        }

        return n;
    }


    protected E maxValue(Node n) {
        if (n == null)
            return null;
        if (n.right == null)
            return n.value;
        return maxValue(n.right);
    }


    protected Node findNode(E val) {
        Node temp = root;

        while (temp != null){
            if(temp.value == val)
                return temp;

            int cmp = val.compareTo(temp.value);
            if (cmp < 0){
                temp = temp.left;

            }

            else{
                temp = temp.right;
            }
        }

        return null;

    }


    protected int depth(E val) {
        Node temp = root;
        int result = 0;

        while (temp != null){
            if(temp.value == val)
                return result;

            int cmp = val.compareTo(temp.value);
            if (cmp < 0)
                temp = temp.left;

            else
                temp = temp.right;

            result++;

        }
        return -1;
    }


    protected static int height(BinarySearchTree<?>.Node n) {
        int height = -1;

        if (n == null) {
            return height;
        } else {
            height = 1 + Math.max(height(n.left), height(n.right));
        }

        return height;
    }

    public static boolean isBalancedNode(BinarySearchTree<?>.Node n) {
        if(n == null)
            return true;

        return Math.abs(height(n.left) - height(n.right)) < 2;
    }

    private boolean isBalancedRecur(Node root){

        if (root == null)
            return true;

        if (isBalancedNode(root) && isBalancedRecur(root.left) && isBalancedRecur(root.right))
            return true;

        return false;
    }
    public boolean isBalanced() {
        return isBalancedRecur(root);
    }


    public boolean isBalancedFast() {
        return true;
    }

    public void print2DUtil(Node root, int space)
    {
        int COUNT = 10;
        // Base case
        if (root == null)
            return;

        // Increase distance between levels
        space += COUNT;

        // Process right child first
        print2DUtil(root.right, space);

        // Print current node after space
        // count
        System.out.print("\n");
        for (int i = COUNT; i < space; i++)
            System.out.print(" ");
        System.out.print(root.value + "\n");

        // Process left child
        print2DUtil(root.left, space);
    }
}
