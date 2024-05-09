//implement binary tree and find all sum
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree{
    Node root;
    BinaryTree(){
        root = null;
    }
    void insert(int data){
        root = insertRec(root, data);
    }
    Node insertRec(Node root, int data){
        if(root == null){
            root = new Node(data);
            return root;
        }
        if(data < root.data){
            root.left = insertRec(root.left, data);
        }else if(data > root.data){
            root.right = insertRec(root.right, data);
        }
        return root;
    }
    void inorder(){
        inorderRec(root);
    }
    void inorderRec(Node root){
        if(root != null){
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }
    void findSum(){
        int sum = 0;
        System.out.println("Sum of all elements in the tree is: " + findSumRec(root, sum));
    }
    int findSumRec(Node root, int sum){
        if(root != null){
            sum = findSumRec(root.left, sum);
            sum += root.data;
            sum = findSumRec(root.right, sum);
        }
        return sum;
    }
}