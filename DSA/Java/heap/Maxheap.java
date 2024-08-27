class Max_priority_queue{
    int[][] p_queue;
    int size;
    int maxSize;

    public Max_priority_queue(int maxSize){
        this.maxSize = maxSize;
        this.size = 0;
        this.p_queue = new int[this.maxSize + 1][2];
        p_queue[0][0] = Integer.MAX_VALUE;
        p_queue[0][1] = Integer.MAX_VALUE;
    }

    public void Heapify_up(int pos){
        while(pos > 1 && p_queue[pos][1] > p_queue[pos/2][1]){
            swap(pos, pos/2);
            pos = pos/2;
        }
    }

    public void swap(int a, int b){
        int temp = p_queue[a][0];
        int temp2 = p_queue[a][1];
        p_queue[a][0] = p_queue[b][0];
        p_queue[a][1] = p_queue[b][1];
        p_queue[b][0] = temp;
        p_queue[b][1] = temp2;
    }

    public void insert(int element, int priority){
        p_queue[++size][0] = element;
        p_queue[size][1] = priority;
        Heapify_up(size);
    }

    public int leftChild(int pos){
        return 2*pos;
    }

    public int rightChild(int pos){
        return 2*pos + 1;
    }

    public void Heapify_down(int pos){
        if(pos > size/2){
            return;
        }
        if(p_queue[pos][1] < p_queue[leftChild(pos)][1] || p_queue[pos][1] < p_queue[rightChild(pos)][1]){
            if(p_queue[leftChild(pos)][1] > p_queue[rightChild(pos)][1]){
                swap(pos, leftChild(pos));
                Heapify_down(leftChild(pos));
            }else{
                swap(pos, rightChild(pos));
                Heapify_down(rightChild(pos));
            }
        }
    }

    public int delete(){
        int popped = p_queue[1][0];
        p_queue[1][0] = p_queue[size][0];
        p_queue[1][1] = p_queue[size--][1];
        p_queue[size + 1][0] = -1;
        p_queue[size + 1][1] = -1;
        Heapify_down(1);
        return popped;
    }

    public void print(){
        for(int i = 1; i <= size/2; i++){
            System.out.print("Parent: " + p_queue[i][0] + " Left Child: " + p_queue[2*i][0] + " Right Child: " + p_queue[2*i + 1][0]); 
            System.out.println();
        }
    }

    public void printArray(){
        for(int i = 1; i <= size; i++){
            System.out.print(p_queue[i][0] + " ");
        }
        System.out.println();
    }
}

class Maxheap{
    int[] heap;
    int[][] p_queue;
    int size;
    int maxSize;

    public Maxheap(int maxSize, boolean priority_queue){
        this.maxSize = maxSize;
        this.size = 0;
        if (priority_queue){
            this.p_queue = new int[this.maxSize + 1][2];
            p_queue[0][0] = Integer.MAX_VALUE;
            p_queue[0][1] = Integer.MAX_VALUE;
        }
        else{
            this.heap = new int[this.maxSize + 1];
            heap[0] = Integer.MAX_VALUE;
        }
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
        if(pos > size/2){
            return;
        }
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

    public int delete(){
        int popped = heap[1];
        heap[1] = heap[size--];
        heap[size + 1] = -1;
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
        Maxheap maxheap = new Maxheap(15, false);
        // for(int i = 1; i <= 7; i++){
        //     maxheap.insert(i);
        // }
        // maxheap.print();
        // maxheap.printArray();
        // System.out.println("The max val is " + maxheap.delete());
        // maxheap.print();
        // maxheap.printArray();

        System.out.println("Priority Queue");
        Max_priority_queue max_priority_queue = new Max_priority_queue(15);
        max_priority_queue.insert(1, 10);
        max_priority_queue.insert(2, 20);
        max_priority_queue.insert(3, 30);
        max_priority_queue.insert(4, 40);
        max_priority_queue.insert(5, 50);
        max_priority_queue.insert(6, 60);
        max_priority_queue.insert(7, 70);
        max_priority_queue.print();
        max_priority_queue.printArray();
        System.out.println("The max val is " + max_priority_queue.delete());
        max_priority_queue.print();
        max_priority_queue.printArray();
    }

}
