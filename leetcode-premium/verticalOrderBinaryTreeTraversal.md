This particular has two versions.

1>We know for a vertical order , multiple nodes can lie at the same Horizontal distance and at the same level .

This fact is used to create Two Versions -> 
 a> In this , when the above condition is seen , vertical ordering prefers from left to right (like inorder ).
 b> In this , You have to sort them according to values . 

 // First lets discuss the various algorithms we canm try for b> 



 A1->
 class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            map<int,vector<int>> s;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* x = q.front().first;
                int pos = q.front().second;
                q.pop();
                s[pos].push_back(x->val);
                if(x->left) q.push({x->left,pos-1});
                if(x->right) q.push({x->right,pos+1});
            }
            for(auto i:s){
                sort(i.second.begin(),i.second.end());
                for(int j=0;j<i.second.size();j++){
                    m[i.first].push_back(i.second[j]);
                }
            }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};

 A2 <!--
   void dfs(TreeNode* root,int dist,map<int,map<int,multiset<int>>> &mp,int row){
        
        if(root==NULL) return;
        
        mp[dist][row].insert(root->val);
        
        dfs(root->left,dist-1,mp,row+1);
        
        
        dfs(root->right,dist+1,mp,row+1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;         // multiset is used here for duplicate nde cases 

        
        dfs(root,0,mp,0);
        
        for(auto x:mp){
            vector<int> tmp;
            
            for(auto y:x.second){
                for(auto z:y.second){
                    tmp.push_back(z);
                }
            }
            ans.push_back(tmp);
            
       
            
            
        }
        
        
        return ans;
        
        
        
        
    } -->

    // Now lets discuss the version a> 


     void bfs(Node* root,unordered_map<int,vector<int>> &mp){
        
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            
            auto tp = q.front();
            q.pop();
            
            int hd = tp.second;
            auto curr = tp.first;
            
            mp[hd].push_back(curr->data);
            
            if(curr->left){
                q.push({curr->left,hd-1});
            }
            
            if(curr->right){
                q.push({curr->right,hd+1});
            }
        }
        
        
        
        
        
        
    }
    
    void dfs1(Node* root,int &minD,int &maxD,int hd){
        
        if(root==NULL){
            return ;
        }
        
        if(hd<minD) minD = hd;
        
        if(hd>maxD)  maxD = hd;
        
        dfs1(root->left,minD,maxD,hd-1);
        dfs1(root->right,minD,maxD,hd+1);
        
        
    }
    vector<int> verticalOrder(Node *root)
    {
     
        int minD=0,maxD=0;
        dfs1(root,minD,maxD,0);
        
        vector<int> ans;
        
        unordered_map<int,vector<int>> mp;
        
        bfs(root,mp);
        
        for(int i=minD;i<=maxD;i++){
            for(auto x:mp[i]){
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};