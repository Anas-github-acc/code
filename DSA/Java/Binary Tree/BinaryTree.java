class TreeNode{
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
    void setupChild(int left, int right){
        this.left = new TreeNode(left);
        this.right = new TreeNode(right);
    }
}
class BinaryTree{
    TreeNode root;
    BinaryTree(){
        this.root = null;
    }
    BinaryTree(int data){
        this.root = new TreeNode(data);
    }

    void printInorder(TreeNode node){
        if(node == null){
            return;
        }
        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }
    void printPostorder(TreeNode node){
        if(node == null){
            return;
        }
        printPostorder(node.left);
        printPostorder(node.right);
        System.out.print(node.data + " ");
    }
    void printPreorder(TreeNode node){
        if(node == null){
            return;
        }
        System.out.print(node.data + " ");
        printPreorder(node.left);
        printPreorder(node.right);
    }
}
class BinaryTree{
    public static void main(String[] args){
        BinaryTree tree = new BinaryTree(1);
        tree.root.setupChild(2, 3);
        tree.root.left.setupChild(4, 5);
        tree.root.right.setupChild(6, 7);
        tree.root.left.left.setupChild(8, 9);
        tree.printInorder(tree.root);
        System.out.println();
        tree.printPostorder(tree.root);
        System.out.println();
        tree.printPreorder(tree.root);
        System.out.println();


    }
}