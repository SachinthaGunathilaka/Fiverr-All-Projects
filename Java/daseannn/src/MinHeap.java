import java.util.ArrayList;
import java.util.Comparator;

public class MinHeap {

    // member variables
    private ArrayList<Integer> Heap;
    private int size;
    private int maxsize;

    // constructor
    public MinHeap(int maxsize) {
        this.maxsize = maxsize;
        this.size = 0;
        Heap = new ArrayList<>();

    }

    // Returning the position of the parent for the node currently at position
    private int parent(int pos) {
        return (pos - 1) / 2;
    }

    // Returning the position of the left child for the node currently at position
    private int leftChild(int pos) {
        return (2 * pos) + 1;
    }

    // Returning the position of the right child for the node currently at position
    private int rightChild(int pos) {
        return (2 * pos) + 2;
    }

    // Returning true if the passed node is a leaf node
    public boolean isLeaf(int pos) {
        if (rightChild(pos) >= size && leftChild(pos) >= size) {
            return true;
        }
        return false;
    }

    // To swap two nodes of the heap
    private void swap(int fpos, int spos) {
        int tmp;
        tmp = Heap.get(fpos);
        Heap.set(fpos, Heap.get(spos));
        Heap.set(spos, tmp);
    }

    void minHeapify(int i) {
        while (Heap.get(i) < Heap.get(parent(i))) {
            swap(i, parent(i));
            i = parent(i);
        }

    }

    public void maxHeapify() {

        for (int i = 1; i < size; i++) {
            if (Heap.get(i) > Heap.get((i - 1) / 2)) {
                int j = i;
                while (Heap.get(j) > Heap.get((j - 1) / 2)) {
                    swap(j, (j - 1) / 2);
                    j = (j - 1) / 2;
                }
            }
        }
    }

    // To insert a node into the heap
    public void insert(int element) {
        if (size >= maxsize) {    //checking whether the array is full
            return;
        }
        Heap.add(element);
        size++;

        minHeapify(size - 1);
    }


    public void sort() {
        maxHeapify();
        for (int i = size - 1; i > 0; i--) {

            swap(0, i);
            int j = 0, index;

            do {
                index = (2 * j + 1);

                if (index < (i - 1) && Heap.get(index) < Heap.get(index + 1))
                    index++;
                if (index < i && Heap.get(j) < Heap.get(index))
                    swap(j, index);

                j = index;

            } while (index < i);
        }
    }

    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.print(Heap.get(i) + " ");
        }
        System.out.println();
    }

    public void removeElement(int element) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (Heap.get(i) == element) {
                index = i;
                break;
            }

        }

        if (index == -1) {
            System.out.println("Element not found");
        } else {
            size--;
            for (int i = index; i < size; i++) {
                Heap.set(i, Heap.get(i + 1));
            }

            for (int i = 0; i < size; i++) {
                minHeapify(i);
            }
        }


    }

    public void sortByStd() {
        Heap.sort(Comparator.naturalOrder());
    }
}
