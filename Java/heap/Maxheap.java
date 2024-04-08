class Maxheap{
    int[] heap;
    int size;
    int maxSize;

    public Maxheap(int maxSize){
        this.maxSize = maxSize;
        this.size = 0;
        heap = new int[this.maxSize + 1];
        heap[0] = Integer.MAX_VALUE;
    }

    public void Heapify_up(int pos){
        while(pos > 1 && heap[pos] > heap[pos/2]){
            swap(pos, pos/2);
            pos = pos/2;
        }
    }

    public void swap(int a, int b){
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }

    public void insert(int element){
        heap[++size] = element;
        Heapify_up(size);
    }

    public int leftChild(int pos){
        return 2*pos;
    }

    public int rightChild(int pos){
        return 2*pos + 1;
    }

    public void Heapify_down(int pos){
        if(!(pos >= (size/2) && pos <= size)){
            if(heap[pos] < heap[leftChild(pos)] || heap[pos] < heap[rightChild(pos)]){
                if(heap[leftChild(pos)] > heap[rightChild(pos)]){
                    swap(pos, leftChild(pos));
                    Heapify_down(leftChild(pos));
                }else{
                    swap(pos, rightChild(pos));
                    Heapify_down(rightChild(pos));
                }
            }
        }
    }

    public int delete(){
        int popped = heap[1];
        heap[1] = heap[size--];
        Heapify_down(1);
        return popped;
    }


    public void print(){
        for(int i = 1; i <= size/2; i++){
            System.out.print("Parent: " + heap[i] + " Left Child: " + heap[2*i] + " Right Child: " + heap[2*i + 1]);
            System.out.println();
        }
    }

    public void printArray(){
        for(int i = 1; i <= size; i++){
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Maxheap maxheap = new Maxheap(15);
        for(int i = 1; i <= 7; i++){
            maxheap.insert(i);
        }
        maxheap.print();
        maxheap.printArray();
        System.out.println("The max val is " + maxheap.delete());
        maxheap.print();
        maxheap.printArray();
    }

}