#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class StackLL{
    private:
        Node* top;
    public:
        StackLL(){
            top = NULL;
        }
        void push(int data){
            Node* newNode = new Node(data);
            if(top == NULL){
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }
    public:
        int pop(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
            }else{
                Node* temp = top;
                // int data = temp->data;
                top = top->next;
                delete temp;
                // return data
            }
        }
    public:
        int peek(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
            }else{
                return top->data;
            }
        }
    public:
        print(){
            Node* temp = top;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

class StackAL{
    private:
        int* arr;
        int top;
        int capacity;
    public:
        StackAL(int capacity){
            this->capacity = capacity;
            arr = new int[capacity];
            top = -1;
        }
    public:
        void push(int data){
            if(top == capacity - 1){
                cout << "Stack is full" << endl;
            }else{
                arr[++top] = data;
            }
        }
    public:
        int pop(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }else{
                return arr[top--];
            }
        }
    public:
        int peek(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }else{
                return arr[top];
            }
        }
    public:
        void print(){
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

};

int main(){
    StackLL s;
    cout<<"Stack using Linked List"<<endl;
    int arr[] = {10, 20, 30, 40, 50};
    for(int i: arr){
        s.push(i);
    }
    s.print();
    cout << s.peek() << endl;
    s.pop();
    s.print();
    cout << s.peek() << endl;
    cout<<"Stack using Array"<<endl;
    StackAL s1(5);
    for(int i: arr){
        s1.push(i);
    }
    s1.print();
    cout << s1.peek() << endl;
    s1.pop();
    s1.print();
    cout << s1.peek() << endl;
    return 0;
}