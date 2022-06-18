public class Solution {
    /*
     * @param : the root of tree
     * @param : the target sum
     * @return: two numbers from tree which sum is n
     */
    public int[] twoSum(TreeNode root, int n) {
        // write your code here
        if (root == null) {
            return null;
        }
        
        TreeNode left = minNode(root);
        TreeNode right = maxNode(root);
        while (left != right) {
            if (left.val + right.val == n) {
                return new int[] {left.val, right.val};
            } else if (left.val + right.val < n) {
                left = inorderSuccessor(root, left);
            } else {
                right = inorderPredecessor(root, right);
            }
        }
        
        return null;
    }
    
    private TreeNode minNode(TreeNode root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }
    
    private TreeNode maxNode(TreeNode root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }
    
    private TreeNode inorderPredecessor(TreeNode root, TreeNode target) {
        TreeNode predecessor = null;
        TreeNode p = root;
        while (p != null) {
            if (p == target) {
                break;
            } else if (p.val < target.val) {
                predecessor = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        
        if (p == null) {
            return null;
        }
        
        if (p.left == null) {
            return predecessor;
        }
        
        p = p.left;
        while (p.right != null) {
            p = p.right;
        }
        
        return p;
    }
    
    private TreeNode inorderSuccessor(TreeNode root, TreeNode target) {
        TreeNode successor = null;
        TreeNode p = root;
        while (p != null) {
            if (p == target) {
                break;
            } else if (p.val < target.val) {
                p = p.right;
            } else {
                successor = p;
                p = p.left;
            }
        }
        
        if (p == null) {
            return null;
        }
        
        if (p.right == null) {
            return successor;
        }
        
        p = p.right;
        while (p.left != null) {
            p = p.left;
        }
        
        return p;
    }
}