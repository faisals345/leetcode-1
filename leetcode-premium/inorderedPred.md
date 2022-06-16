 TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        TreeNode * fa = NULL;

        while (root && root != p) {
            if (root->val < p->val)
                fa=root,root = root->right;
            else {
                // fa = root;
                root = root->left;
            }
        }
        
        if (root == NULL)
            return NULL;
        if (root->left == NULL)
            return fa;
            
        root = root->left;
        while (root->right)
            root = root->right;
        return root;
    }