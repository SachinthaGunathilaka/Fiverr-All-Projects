import java.util.ArrayList;
import java.util.Comparator;

public class MinHeap {

    // member variables
//    private int[] Heap;
    private ArrayList<Integer> Heap;
    private int size;
    private int maxsize;

    // Initializing front as static
    private static final int FRONT = 0;

    // constructor
    public MinHeap(int maxsize) {
        //This keyword refers to current object itself
        this.maxsize = maxsize;
        this.size = 0;

//        Heap = new int[this.maxsize];           // create array of integers
        Heap = new ArrayList<>();

    }

    // Returning the position of the parent for the node currently at position
    private int parent(int pos) {
        return (pos - 1) / 2;
    }

    // Returning the position of the leftchild for the node currently at position
    private int leftChild(int pos) {
        return (2 * pos) + 1;
    }

    // Returning the position of the right child for the node currently at position
    private int rightChild(int pos) {
        return (2 * pos) + 2;
    }

    // Returning true if the passed node is a leaf node(any node whose left and right children are null)
    public boolean isLeaf(int pos) {
        if (rightChild(pos) >= size && leftChild(pos) >= size) {
            return true;
        }
        return false;
//        if (pos > (size / 2) - 1 && pos <= size - 1) {
//            return true;
//        }

//        return false;
    }

    // To swap two nodes of the heap
    private void swap(int fpos, int spos) {
        int tmp;
//        tmp = Heap[fpos];           //save node value
        tmp = Heap.get(fpos);

        //swapping
//        Heap[fpos] = Heap[spos];
        Heap.set(fpos, Heap.get(spos));
//        Heap[spos] = tmp;
        Heap.set(spos, tmp);
    }

    void heapify(int i) {

//        while (Heap[i] < Heap[parent(i)]) {
        while (Heap.get(i) < Heap.get(parent(i))) {
            swap(i, parent(i));
            i = parent(i);
        }


//        int largest = i; // Initialize largest as root
//        int l = 2 * i + 1; // left = 2*i + 1
//        int r = 2 * i + 2; // right = 2*i + 2
//
//        // If left child is larger than root
//        if (l < size && Heap[l] > Heap[largest])
//            largest = l;
//
//        // If right child is larger than largest so far
//        if (r < size && Heap[r] > Heap[largest])
//            largest = r;
//
//        // If largest is not root
//        if (largest != i) {
//            int swap = Heap[i];
//            Heap[i] = Heap[largest];
//            Heap[largest] = swap;
//
//            // Recursively heapify the affected sub-tree
//            heapify(largest);
//        }
    }
//
//    // To heapify the node at pos
//    private void minHeapify(int pos) {
//
//        // if the node is a non-leaf node
//        if (!isLeaf(pos)) {
//            System.out.println("p" + pos);
//            System.out.println("S" + size);
//            // check whether the value is greater than left and right child values
//            if (Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {
//
//                // if leftchild < rightchild, swap with the left child and heapify the left child
//                if (Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
//                    swap(pos, leftChild(pos));          // swap node with left child
//                    minHeapify(leftChild(pos));         // heapify the left child
//                }
//                // else swap with the right child and heapify the right child
//                else {
//                    swap(pos, rightChild(pos));         // swap node with right child
//                    minHeapify(rightChild(pos));       // heapify the right child
//                }
//            }
//        }
//    }

    // To insert a node into the heap
    public void insert(int element) {
        if (size >= maxsize) {    //checking whether the array is full
            return;
        }

//        Heap[size] = element;
        Heap.add(element);

//        int current = size;
//
//        while (Heap[current] < Heap[parent(current)]) {
//            swap(current, parent(current));
//            current = parent(current);
//        }
        size++;

        heapify(size - 1);
    }

    public void maxHeapify() {
//        for (int i = 0; i < n; i++) {
//            size++;
//            Heap[i] = arr[i];
//        }
        for (int i = 1; i < size; i++) {
            // if child is bigger than parent
//            if (Heap[i] > Heap[(i - 1) / 2]) {
            if (Heap.get(i) > Heap.get((i - 1) / 2)) {
                int j = i;

                // swap child and parent until
                // parent is smaller
//                while (Heap[j] > Heap[(j - 1) / 2]) {
                while (Heap.get(j) > Heap.get((j - 1) / 2)) {
                    swap(j, (j - 1) / 2);
                    j = (j - 1) / 2;
                }
            }
        }
    }

    public void sort() {
        maxHeapify();
        for (int i = size - 1; i > 0; i--) {
            // swap value of first indexed
            // with last indexed
            swap(0, i);

            // maintaining heap property
            // after each swapping
            int j = 0, index;

            do {
                index = (2 * j + 1);

                // if left child is smaller than
                // right child point index variable
                // to right child
//                if (index < (i - 1) && Heap[index] < Heap[index + 1])
                if (index < (i - 1) && Heap.get(index) < Heap.get(index + 1))
                    index++;

                // if parent is smaller than child
                // then swapping parent with child
                // having higher value
//                if (index < i && Heap[j] < Heap[index])
                if (index < i && Heap.get(j) < Heap.get(index))
                    swap(j, index);

                j = index;

            } while (index < i);
        }


//        System.out.println("Sicze" + size);
//
////        int n = arr.length;
//
//        // Build heap (rearrange array)
//        for (int i = size / 2 - 1; i >= 0; i--) {
//            System.out.println(i);
//            heapify(i);
//        }
//
//
//        // One by one extract an element from heap
//        for (int i = size - 1; i > 0; i--) {
//            // Move current root to end
//            int temp = Heap[0];
//            Heap[0] = Heap[i];
//            Heap[i] = temp;
//
//            // call max heapify on the reduced heap
//            heapify(0);
//
//        }
    }

    // To print the contents of the heap
//    public void print(){
//        for (int i=0; i<=(size/2)-1; i++){
//            //printing the parent and both childrens
//            System.out.print(
//                    " PARENT : "+ Heap[i] + " LEFT CHILD : " + Heap[2 * i + 1] + " RIGHT CHILD : " + Heap[2 * i + 2]
//            );
//
//            //By here new line is required
//            System.out.println();
//        }
//    }

    public void print() {
        for (int i = 0; i < size; i++) {
//            System.out.print(Heap[i] + " ");
            System.out.print(Heap.get(i) + " ");
        }
        System.out.println();
    }

//    // To remove and return the minimum element from the heap
//    public int pop() {
//        // Get the minimum value that is being removed
////        int popped = Heap[FRONT];
//        int popped = Heap.get(FRONT);
//        // Bring the last element in the heap to the front
////        Heap[FRONT] = Heap[size - 1];
//        Heap.set(FRONT, Heap.get(size - 1));
//
//        // Call minHeapify function to order the nodes correclty.
//        minHeapify(FRONT);
//
//        size--;
//
//        return popped;
//    }

    public void removeElement(int element) {
        int index = -1;
        for (int i = 0; i < size; i++) {
//            if (Heap[i] == element) {
            if (Heap.get(i) == element) {
                index = i;
                break;
            }

        }
        System.out.println("i" + index);

        if (index == -1) {
            System.out.println("Element not found");
        } else {
            size--;
            for (int i = index; i < size; i++) {
//                Heap[i] = Heap[i + 1];
                Heap.set(i, Heap.get(i + 1));
            }
        }

        for (int i = 0; i < size; i++) {
            heapify(index);
        }
    }

    public void sortByStd(){
        Heap.sort(Comparator.naturalOrder());
    }

    // Main driver method
//    public static void main(String[] args) {
//
//
//        MinHeap minHeap = new MinHeap(15);
//
//        minHeap.insert(5);
//        minHeap.insert(3);
//        minHeap.insert(17);
//        minHeap.insert(10);
//        minHeap.insert(84);
//        minHeap.insert(19);
//        minHeap.insert(6);
//        minHeap.insert(22);
//        minHeap.insert(9);
//
//
//        minHeap.print();


//        // Removing minimum value from above heap and printing it
//        int val = minHeap.remove();
//        System.out.println("\nThe Min val is "+ val);
//
//
//        System.out.println("\nAfter removing "+ val);
//        // Print all the elements of the heap
//        minHeap.print();

//    }

}
