import java.util.ArrayList;

class Queue {
    private ArrayList<Integer> queue = new ArrayList<Integer>();

    public void enqueue(int data) {
        queue.add(data);
    }

    public int dequeue() {
        if (queue.isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return queue.remove(0);
    }

    public int peek() {
        if (queue.isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }
        return queue.get(0);
    }
    public int size() {
        return queue.size();
    }
}

public class queueAL {
    public static void main(String[] args) {
        Queue q = new Queue();
        for(int i = 3; i < 12; i+=2)
            q.enqueue(i);
        System.out.println(q.dequeue());
        System.out.println(q.peek());
        System.out.println(q.size());
    }
}


// class Queue_ArrayList {
//     int[] arr;
//     int front;
//     int rear;
//     int capacity;

//     Queue_ArrayList() {
//         capacity = 1;
//         arr = new int[capacity];
//         front = 0;
//         rear = 0;
//     }
//     Queue_ArrayList(int cap) {
//         capacity = cap;
//         arr = new int[capacity];
//         front = 0;
//         rear = 0;
//     }

//     int expand() {
//         capacity *= 2;
//         int[] t_arr = new int[capacity];
//         for (int i = 0; i < rear; i++) {
//             t_arr[i] = arr[i];
//         }
//         arr = t_arr;
//         return capacity;
//     }
//     void enqueue(int data) {
//         if (rear == capacity) {
//             expand();
//         }
//         arr[rear++] = data;
//     }
//     int dequeue() {
//         if (front == rear) {
//             throw new.RuntimeException("Queue is empty");
//         }
//         return arr[front++];
//     }

//     int peek() {
//         if (front == rear) {
//             expand();
//         }
//         return arr[front];
//     }

//     int size() {
//         return rear - front;
//     }

//     boolean isEmpty() {
//         return front == rear;
//     }
// }

// public class queueAL {
//     public static void main(String[] args) {
//         Queue_ArrayList q = new Queue_ArrayList();
//         for (int i = 1; i < 7; i += 1){
//             q.enqueue(i);
//             // System.out.println("size = "+q.size());
//         }
//         System.out.println(q.dequeue());
//         System.out.println(q.peek());
//         System.out.println(q.size());
//     }
// }