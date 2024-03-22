class CNode {
    int data;
    CNode next;
    CNode(int data) {
        this.data = data;
        this.next = null;
    }
}
class CircularLinkedList{
    CNode head = null;
    int size;
    CircularLinkedList(){
        this.head = null;
        this.size = 0;
    }
    void add(int data){
        CNode new_node = new CNode(data);
        if(this.head == null){
            this.head = new_node;
            this.head.next = this.head;
        }
        else{
            CNode temp = this.head;
            while(temp.next != this.head){
                temp = temp.next;
            }
            temp.next = new_node;
            new_node.next = this.head;
        }
        this.size++;
    }
    void add(int data, int index){
        CNode new_node = new CNode(data);
        if(this.head == null){
            this.head = new_node;
            this.head.next = this.head;
        }
        else if(index == 0){
            new_node.next = this.head;
            CNode temp = this.head;
            while(temp.next != this.head){
                temp = temp.next;
            }
            temp.next = new_node;
            this.head = new_node;
        }
        else{
            CNode temp = this.head;
            for(int i = 0; i < index - 1; i++){
                temp = temp.next;
            }
            new_node.next = temp.next;
            temp.next = new_node;
        }
    }
    void remove(int index){
        if(index == 0){
            CNode temp = this.head;
            while(temp.next != this.head){
                temp = temp.next;
            }
            temp.next = this.head.next;
            this.head = this.head.next;
        }
        else{
            CNode temp = this.head;
            for(int i = 0; i < index - 1; i++){
                temp = temp.next;
            }
            temp.next = temp.next.next;
        }
        this.size--;
    }
    void print(){
        CNode temp = this.head;
        do{
            System.out.print(temp.data + " ");
            temp = temp.next;
        }while(temp != this.head);
    }
}
class circularLL{
    public static void main(String[] args) {
        CircularLinkedList cll = new CircularLinkedList();
        for(int i = 0; i < 5; i++){
            cll.add(i);
        }
        cll.print();
        System.out.println();
        cll.add(5, 0);
        cll.print();
        System.out.println();
        cll.remove(2);
        cll.print();
        return;
    }
}