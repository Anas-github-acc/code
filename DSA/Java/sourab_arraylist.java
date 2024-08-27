class ArrayList{
    int[] arr;
    int cap;
    int size;

    ArrayList() {
        cap = 1;
        size = 0;
        arr = new int[cap];
    }

    int size(){
        return size;
    }

    void expand() {
        cap *= 2;
        int[] temp = new int[cap];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
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
        return l;
    }

    void add(int item){
        int index = binarySearch(item);
        if (size >= cap) {
            expand();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        size++;
    }

    void remove(int index) {
        for(int i = index; i < size - 1; i++){
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
        return (int) arr[index];
    }
}

class sourab_arraylist{
    static void print(ArrayList aa) {
        System.out.print("[");
        for (int i=0; i<aa.size(); i++) {
            System.out.print(aa.get(i)+", ");
        }
        System.out.println("]");
    }
    public static void main(String[] args) {
        ArrayList aa = new ArrayList();
        for(int i=10; i>0; i--){
            aa.add(i);
        }
        aa.add(75);
        aa.add(100);
        System.out.print("printing my array = ");
        print(aa);
        System.out.print("array after removing element at index 1 = ");
        aa.remove(1);
        print(aa);
        System.out.println("size of the array = "+aa.size());
    }
}