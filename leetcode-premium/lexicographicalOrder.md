Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]





class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for(int i = 1; i <= n; i++){
            res.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++;
            } else {
                while ((curr / 10) % 10 == 9) {
                    curr /= 10;
                }
                curr = curr / 10 + 1;
            }
        }
        return res;
    }
    
};



// approach 2 
class Solution {
    vector<int> ans;    //Created answer vector
public:
    void dfs(int currN,int n){
        if(currN > n) return;   // if Current-Node is out of range 
        ans.push_back(currN);
        for(int i=0; i<10; i++){    // Simply travel DFS
            dfs(currN*10+i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<10; i++){
            dfs(i,n);
        }
        return ans;
    }    
};
// Time Complexity :: O(N)
// As we travel each node, just 1 time
// Extra Space :: O(1)
