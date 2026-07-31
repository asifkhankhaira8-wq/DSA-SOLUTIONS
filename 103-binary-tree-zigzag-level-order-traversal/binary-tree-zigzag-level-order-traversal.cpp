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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       if(root==NULL) return {};
       vector<vector<int>>ans;
       queue<TreeNode*>q;
       q.push(root); 
       bool b=false;
       while(!q.empty()){
        int size=q.size();
        vector<int>temp(size);
        for(int i=0;i<size;i++){
            TreeNode* top=q.front();
            q.pop();
            if(b) temp[size-i-1]=top->val;
            else temp[i]=top->val;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        b=!b;
        ans.push_back(temp);
       }
       return ans;
    }
};