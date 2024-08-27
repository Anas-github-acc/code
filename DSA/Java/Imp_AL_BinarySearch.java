import java.util.*;
import java.io.*;

class ArrayList {
    int[] arr;
    int capacity = 1;
    int size;

    ArrayList(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }
    ArrayList() {
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }
    void expand() {
        capacity *= 2;
        int[] t_arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            t_arr[i] = arr[i];
        }
        arr = t_arr;
    }
    int binarySearch(int x) {
        int cnt = 0;
        int l = 0, r = size - 1;
        while(l <= r){
            cnt++;
            int m = l + (r - l) / 2;
            if (get(m) == x)
                return m;
            if (get(m) < x)
                l = m + 1;
            else
                r = m - 1;
        }
        System.out.println("operation : "+cnt+" ");
        return l;
    }
    void add(int item) {
        int index = binarySearch(item);
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        if (size == capacity) {expand();}
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        size++;
    }
    void remove(int item) {
        int idx = binarySearch(item);
        if(idx < 0 || idx >size) {
            throw new IndexOutOfBoundsException();
        }
        for(int i = idx; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }
    int indexOf(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    int get(int index) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        return (int) arr[index];
    }
    int size(){
        return size;
    }
}

class Imp_AL_BinarySearch{
    
    static void print_myarray(ArrayList arr) {
        for (int i=0; i<arr.size(); i++) {
            System.out.print(arr.get(i)+", ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Imp_AL_BinarySearch obj = new Imp_AL_BinarySearch();
        ArrayList arr = new ArrayList();
        arr.add( 5);
        arr.add( 100);
        arr.add( 0);
        arr.add( 47);
        arr.add( 2);
        arr.add( 3);
        arr.add( 35);
        print_myarray(arr);
        arr.remove(3);
        print_myarray(arr);

    }
}