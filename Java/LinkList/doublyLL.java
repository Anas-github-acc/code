class D_Node{
    int data;
    D_Node next;
    D_Node prev;
    D_Node(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
class doublyLinkedList{
    D_Node head;
    D_Node tail;
    int size;
    doublyLinkedList(){
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    void add(int data){
        D_Node new_node = new D_Node(data);
        if(this.head == null){
            this.head = new_node;
            this.tail = new_node;
        }
        else{
            this.tail.next = new_node;
            new_node.prev = this.tail;
            this.tail = new_node;
        }
        this.size++;
    }
    void add(int data, int index){
        D_Node new_node = new D_Node(data);
        if(this.head == null){
            this.head = new_node;
            this.tail = new_node;
        }
        else if(index == 0){
            new_node.next = this.head;
            this.head.prev = new_node;
            this.head = new_node;
        }
        else{
            D_Node temp = this.head;
            for(int i = 0; i < index - 1; i++){
                temp = temp.next;
            }
            new_node.next = temp.next;
            new_node.prev = temp;
            temp.next = new_node;
            new_node.next.prev = new_node;
        }
        this.size++;
    }
    void remove(int index){
        if(index == 0){
            this.head = this.head.next;
            this.head.prev = null;
        }
        else{
            D_Node temp = this.head;
            for(int i = 0; i < index - 1; i++){
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
        }
        this.size--;
    }
}


class d+{
    public static void main(String[] args) {
        doublyLinkedList dll = new doublyLinkedList();
        for(int i = 0; i < 5; i++){
            dll.add(i*100);
        }
        dll.add(1, 0);
        dll.add(2, 1);
        dll.add(3, 2);
        dll.add(4, 3);
        dll.add(45, 0);
        D_Node temp = dll.head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
}