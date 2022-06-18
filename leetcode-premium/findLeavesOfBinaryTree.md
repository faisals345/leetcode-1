Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Input: {1,2,3,4,5}
Output: [[4, 5, 3], [2], [1]].

    1
   / \
  2   3
 / \     
4  5

The algorithm is store nodes according to their depth , the leaf nodes will be at level 0 so on , the next leaf node will be at level 1 


 <!-- vector<vector<int>> ans;

    int dfs(TreeNode* root){
        if(!root) return -1;

        int p1 = dfs(root->left);

        int p2 = dfs(root->right);

        int curr = max(p1,p2)+1;

        if(ans.size()<=curr){
            ans.push_back({root->val});
        }
        else{
            ans[curr].push_back(root->val);
        }

        return curr;

    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here

        dfs(root);

        return ans;
    } -->