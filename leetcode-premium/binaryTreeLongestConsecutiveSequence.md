<!-- Given a binary tree, find the length(number of nodes) of the longest consecutive sequence(Monotonic and adjacent node values differ by 1) path.
The path could be start and end at any node in the tree -->



     int res = 1;

     
    pair<int,int> helper(TreeNode* root,TreeNode* par){

        if(root==NULL) return {0,0};

       pair<int,int> p1  =  helper(root->left,root);


       pair<int,int> p2 =  helper(root->right,root);

        if(root==par){
                res = max(res, max(p1.first+1+p2.second,p1.second+1+p2.first));
        }
        else{
            
             res = max(res, max(p1.first+1+p2.second,p1.second+1+p2.first));
             
            int p_v = par->val;
            int r_v = root->val; 

            if(p_v!=r_v+1 && p_v+1!=r_v) return {0,0};

           

            if(p_v==r_v+1){
                    return {0,max(p1.second,p2.second)+1};
            }
            else{
                    return {max(p1.first,p2.first)+1,0};
            }



        }


        return {0,0};




    }
    int longestConsecutive2(TreeNode *root) {
        // write your code here

        helper(root,root);

        return res;
    }
