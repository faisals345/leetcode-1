First determine the successor of the inorder traversal:

If the node has a right child, then the successor is the leftmost node in the subtree of its right child
If the node has no right child, then the successor is its nearest ancestor, and the node is in the left subtree of this ancestor.
Use a loop to achieve:

Find the node, and in the process maintain ancestor nodes of the above properties
After finding, if the node has a right child node, the successor is in its right subtree; otherwise, the successor is the ancestor node maintained


##

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {

        TreeNode * fa = NULL;
        while (root && root != p) {
            if (root->val < p->val)
                root = root->right;
            else {
                fa = root;
                root = root->left;
            }
        }
        
        if (root == NULL)
            return NULL;
        if (root->right == NULL)
            return fa;
            
        root = root->right;
        while (root->left)
            root = root->left;
        return root;





    }

















##