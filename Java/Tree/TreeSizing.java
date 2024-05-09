//find diameter of tree and longest path between any two nodes in lon(n) operation

// function findDiameter(root) {
//     let ans = 0;
//     let curr = root;
 
//     while (curr != null) {
//         if (curr.left == null) {
//             curr = curr.right;
//         } else {
//             let pre = curr.left;
//             while (pre.right != null && pre.right != curr) {
//                 pre = pre.right;
//             }
//             if (pre.right == null) {
//                 pre.right = curr;
//                 curr = curr.left;
//             } else {
//                 pre.right = null;
//                 let leftHeight = 0, rightHeight = 0;
//                 let temp = curr.left;
//                 while (temp != null) {
//                     leftHeight++;
//                     temp = temp.right;
//                 }
//                 temp = curr.right;
//                 while (temp != null) {
//                     rightHeight++;
//                     temp = temp.left;
//                 }
//                 ans = Math.max(ans, leftHeight + rightHeight + 1);
//                 curr = curr.right;
//             }
//         }
//     }
//     return ans;
// }
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
    int findingDiameter(TreeNode root){
        int ans = 0;
        TreeNode curr = root;
        while(curr != null){
            if(curr.left == null){
                curr = curr.right;
            }else{
                TreeNode pre = curr.left;
                while(pre.right != null && pre.right != curr){
                    pre = pre.right;
                }
                if(pre.right == null){
                    pre.right = curr;
                    curr = curr.left;
                }else{
                    pre.right = null;
                    int leftHeight = 0, rightHeight = 0;
                    TreeNode temp = curr.left;
                    while(temp != null){
                        leftHeight++;
                        temp = temp.right;
                    }
                    temp = curr.right;
                    while(temp != null){
                        rightHeight++;
                        temp = temp.left;
                    }
                    ans = Math.max(ans, leftHeight + rightHeight + 1);
                    curr = curr.right;
                }
            }
        }
        return ans;
    }
    int findHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        return 1 + Math.max(findHeight(root.left), findHeight(root.right));
    }
}
class TreeSizing{
    public static void main(String[] args){
        BinaryTree tree = new BinaryTree(1);
        tree.root.setupChild(2, 3);
        tree.root.left.setupChild(4, 5);
        tree.root.right.setupChild(6, 7);
        tree.root.left.left.setupChild(8, 9);
        System.out.println(tree.findingDiameter(tree.root));
        System.out.println(tree.findHeight(tree.root));
    }
}