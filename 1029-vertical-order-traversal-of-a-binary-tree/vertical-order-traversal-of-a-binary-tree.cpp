/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0]>b[0];   
            if (a[1] != b[1]) return a[1]>b[1];   
            return a[2] > b[2];                     
        }
    };
priority_queue<vector<int>,vector<vector<int>>,comp>pq;
void dfs(TreeNode* root,int row ,int col){
    if(root==NULL) return;
    pq.push({col,row,root->val});
    dfs(root->left,row+1,col-1);
    dfs(root->right,row+1,col+1);

}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root,0,0);
        while(!pq.empty()){
             auto top=pq.top();
             pq.pop();
             vector<int>temp;
             temp.push_back(top[2]);
             int col=top[0];
             while(!pq.empty() && pq.top()[0]==col){
                   temp.push_back(pq.top()[2]);
                   pq.pop();
             }
             ans.push_back(temp);
        }
        return ans;
        
    }
};