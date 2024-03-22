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
    int size(){
        return this.size;
    }
    LLNode<T> reverse_linklist(LLNode<T> head){
        LLNode<T> prev = null;
        LLNode<T> current = head;
        LLNode<T> next = null;
        while(current != null){
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    T middle_element(){
        LLNode<T> slow = this.head;
        LLNode<T> fast = this.head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow.data;
    }
}

class LinkList2{
    public static void main(String[] args){
        LinkedList<Integer> obj = new LinkedList<>();
        obj.head = new LLNode(0);
        LLNode temp = obj.head;
        for(int i=1;i<7;i++){
            temp.next = new LLNode(i);
            temp = temp.next;
        }
        temp = obj.head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
        obj.head = obj.reverse_linklist(obj.head);
        temp = obj.head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
        System.out.println(obj.middle_element());

    }
}