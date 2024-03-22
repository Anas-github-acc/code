class LLNode<T>{
    T data;
    LLNode<T> next;
    LLNode(T data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList<T>{
    LLNode<T> head;
    int size;
    LinkedList(){
        this.head = null;
        this.size = 0;
    }
    void add(T data){
        LLNode<T> new_node = new LLNode<>(data);
        if(this.head == null){
            this.head = new_node;
        }else{
            LLNode<T> temp = this.head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = new_node;
        }
        this.size++;
    }
    void add(T data, int index){
        LLNode<T> new_node = new LLNode<>(data);
        if(this.head == null){
            this.head = new_node;
        }else{
            LLNode<T> temp = this.head;
            for(int i = 0; i < index - 1; i++){
                temp = temp.next;
            }
            new_node.next = temp.next;
            temp.next = new_node;
        }
        this.size++;
    }
    void first(T data){
        LLNode<T> new_node = new LLNode<>(data);
        new_node.next = this.head;
        this.head = new_node;
        this.size++;
    }
    void remove(T data){
        LLNode<T> temp = this.head;
        LLNode<T> prev = null;
        if(temp != null && temp.data == data){
            this.head = temp.next;
            this.size--;
            return;
        }
        while(temp != null && temp.data != data){
            prev = temp;
            temp = temp.next;
        }
        if(temp == null){
            return;
        }
        prev.next = temp.next;
        this.size--;
    }
    int size(){
        return this.size;
    }
}

class LinkList{
    public static void printlist(LinkedList<Integer> ll){
        LLNode<Integer> temp = ll.head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        LinkedList<Integer> ll = new LinkedList<>();
        ll.add(10);
        ll.add(20);
        ll.add(30);
        ll.add(40);
        ll.add(50);
        System.out.print("Array : ");
        printlist(ll);
        ll.first(60);
        System.out.print("first : ");
        printlist(ll);
        ll.add(70, 0);
        System.out.print("At Indes : ");
        printlist(ll);
        ll.remove(30);
        System.out.print("remove : ");
        printlist(ll);
        System.out.println("size = "+ll.size());
    } 
}