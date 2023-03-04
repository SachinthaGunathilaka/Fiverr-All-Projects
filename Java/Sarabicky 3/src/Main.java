public class Main {
    public static void main(String[] args) {
        BinarySearchTree<Integer> bst = new BinarySearchTree<Integer>();

        bst.add(10);
        bst.add(5);
        bst.add(7);
        bst.add(3);
        bst.add(9);
        bst.add(15);
        bst.add(2);
        bst.add(14);
        bst.add(1);

//        BinarySearchTree.Node node15 = bst.findNode(13);
//        bst.print2DUtil(node15, 2);

//        System.out.println(bst.depth(10));
//        System.out.println(bst.depth(5));
//        System.out.println(bst.depth(15));
//        System.out.println(bst.depth(14));
//        System.out.println(bst.depth(2));
//        System.out.println(bst.depth(3));
//        System.out.println(bst.depth(7));

//        BinarySearchTree.Node node15 = bst.findNode(15);
//        System.out.println(BinarySearchTree.height(node15));
//
//        BinarySearchTree.Node node10 = bst.findNode(10);
//        System.out.println(BinarySearchTree.height(node10));
//
//        BinarySearchTree.Node node5 = bst.findNode(5);
//        System.out.println(BinarySearchTree.height(node5));
//
//        BinarySearchTree.Node node14 = bst.findNode(14);
//        System.out.println(BinarySearchTree.height(node14));
//
//        BinarySearchTree.Node node13 = bst.findNode(13);
//        System.out.println(BinarySearchTree.height(node13));


//        BinarySearchTree.Node node15 = bst.findNode(15);
//        System.out.println(BinarySearchTree.isBalancedNode(node15));
//
//        BinarySearchTree.Node node10 = bst.findNode(10);
//        System.out.println(BinarySearchTree.isBalancedNode(node10));
//
//        BinarySearchTree.Node node5 = bst.findNode(5);
//        System.out.println(BinarySearchTree.isBalancedNode(node5));
//
//        BinarySearchTree.Node node14 = bst.findNode(14);
//        System.out.println(BinarySearchTree.isBalancedNode(node14));

        System.out.println(bst.isBalanced());



    }
}
