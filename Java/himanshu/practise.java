class ArrayList{
    int[] arr;
    int cap;
    int size;
    ArrayList(){
        cap = 1;
        size = 0;
        arr = new int[cap];
    }
    ArrayList(int cap){
        this.cap = cap;
        size = 0;
        arr = new int[cap];
    }
    void BrinjalExpand(){
        cap *= 2;
        int[] aalo = new int[cap];
        for(int i =0;i<size;i++){
            aalo[i] = arr[i];
        }
        arr = aalo;
    }
    void OnionAdd(int item){
        if(size == cap){
            BrinjalExpand();
        }
        arr[size++] = item;
    }
}

class practise{
    public static void main(String[] args) {
        ArrayList arr = new ArrayList();
        arr.OnionAdd(45);
        arr.OnionAdd(54);
        for(int i= 0; i<arr.size;i++){
            System.out.println(arr.arr[i]);
        }
    }
}