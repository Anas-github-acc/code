class ArrayList<T>{
    Object[] arr;
    int capacity = 1;
    int size;

    ArrayList(int cap) {
        capacity = cap;
        size = 0;
        arr = new Object[capacity];
    }
    ArrayList() {
        capacity = 1;
        size = 0;
        arr = new Object[capacity];
    }
    void expand() {
        capacity *= 2;
        Object[] t_arr = new Object[capacity];
        for (int i = 0; i < size; i++) {
            t_arr[i] = arr[i];
        }
        arr = t_arr;
    }
    void add(T item){
        if(size == capacity){expand();}
        arr[size++] = item;
    }
    void add(int index, T item){
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
    void push(T item) {
        if (size == capacity){expand();}
        for (int i = size; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        set(0, item);
    }
    void remove(int idx) {
        if(idx < 0 || idx > size) {
            throw new IndexOutOfBoundsException();
        }
        for(int i = idx; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    T pop() {
        size--;
        return (T) arr[size];
    }

    int indexOf(T element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    void removeItem(T element) {
        remove(indexOf(element));
    }

    T get(int index) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        return (T) arr[index];
    }
    boolean isElement(T element){
        if(indexOf(element) == -1){
            return false;
        }else{
            return true;
        }
    }
    int size(){
        return size;
    }
    void size(int new_size){
        while(capacity<new_size){
            capacity *= 2;
            Object[] t_arr = new Object[capacity];
        }
        size=new_size;
    }
    void set(int index, T item) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        arr[index] = item;
    }
    boolean isEmpty() {
        return size == 0;
    }
    void clear() {
        size = 0;
    }
}

class ArrayList_Me {
    static void print_myarray(ArrayList<Integer> arr) {
        for (int i=0; i<arr.size(); i++) {
            System.out.print(arr.get(i)+", ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(45);
        arr.add(34);
        arr.add(345);
        arr.add(4);
        arr.add(3);
        print_myarray(arr);
        arr.remove(1);
        print_myarray(arr);
        System.out.println("Size = "+arr.size());
        arr.add(1, 100);
        print_myarray(arr);
    }
}