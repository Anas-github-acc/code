class StackAL{
    private int[] stack;
    private int top;
    private int size;

    public StackAL(int size){
        this.size = size;
        stack = new int[size];
        top = -1;
    }

    public void push(int data){
        if(top == size - 1){
            System.out.println("Stack is full");
            return;
        }
        stack[++top] = data;
    }

    public int pop(){
        if(top == -1){
            System.out.println("Stack is empty");
            return -1;
        }
        return stack[top--];
    }

    public int peek(){
        if(top == -1){
            System.out.println("Stack is empty");
            return -1;
        }
        return stack[top];
    }
    public void display(){
        if(top == -1){
            System.out.println("Stack is empty");
            return;
        }
        for(int i = top; i >= 0; i--){
            System.out.println(stack[i]);
        }
    }

    public static void main(String[] args){
        StackAL stack = new StackAL(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);
        stack.display();
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
        stack.display();
        System.out.println("Peek: " + stack.peek());
    }
}