import java.util.*;

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
            System.out.println("State: Stack is empty");
            return -1;
        }else{
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

class Stack{
    Queue q1;
    Queue q2;
    Stack(){
        this.q1 = new Queue();
        this.q2 = new Queue();
    }
    void push(int data){
        q1.enqueue(data);
    }
    int pop(){
        int data = 0;
        if(q1.size() == 0){
            // System.out.print("Status : Stack is empty ");
            return -1;
        }
        else{
            while(q1.size() > 1){
                q2.enqueue(q1.dequeue());
            }
            data = q1.dequeue();
            Queue temp = q1;
            q1 = q2;
            q2 = temp;
        }
        return data;
    }
}


class stack2Q{
    private static int test(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int para[] = new int[n];
        String s = sc.next();
        for(int i=0;i<n;i++){
            para[i] = s.charAt(i);
        }
        Stack stk = new Stack();
        // int n = 6;
        // int[] para = {'(', '[', ']', ')', '}', '}'};
        for(int i: para){
            if(i == 123 || i == 40 || i == 91){
                stk.push(i);
                // System.out.println(i);
            }else{
                int pop_val = stk.pop();
                // System.out.println("i = "+i+"; pop = "+pop_val);
                if(pop_val == -1){
                    System.out.println("Not Valid");
                    return 0;
                }
                if(i - pop_val > 2 || i - pop_val <= 0){
                    System.out.println("Not Valid");
                    return 0;
                }
            }
        }
        if(stk.pop() == -1)
            System.out.println("Valid");
        else
            System.out.println("Not valid");
        return 1;
    }
    
    public static void main(String args[]){
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0;i<t;i++){
            test();
        }
        // test();
    }
}