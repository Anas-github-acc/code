class Node{
    int data;
    Node next;
    Node(int data){
        this.data = data;
        this.next = null;
    }
}
class Queue{
    Node head;
    int size;
    Queue(){
        this.head = null;
        this.size = 0;
    }
    void enqueue(int data){
        Node new_node = new Node(data);
        if(this.head == null){
            this.head = new_node;
        }
        else{
            Node temp = this.head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = new_node;
        }
        this.size++;
    }
    int dequeue(){
        int data = 0;
        if(this.head == null){
            System.out.print("Status : Queue is empty ");
            return -1;
        }
        else{
            data = this.head.data;
            this.head = this.head.next;
            this.size--;
        }
        return data;
    }
    int size(){
        return size;
    }
}

public class queueLL{
    public static void main(String[] args){
        Queue q = new Queue();
        for(int i = 1; i < 5; i+=1)
            q.enqueue(i*10);
        System.out.println(q.dequeue());
        System.out.println(q.size());
    }
}