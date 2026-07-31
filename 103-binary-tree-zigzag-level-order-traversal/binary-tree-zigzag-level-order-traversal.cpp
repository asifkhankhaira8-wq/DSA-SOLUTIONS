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
        vector<int>temp;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* top=q.front();
            q.pop();
            temp.push_back(top->val);
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        if(b) reverse(temp.begin(),temp.end());
        b=!b;
        ans.push_back(temp);
       }
       return ans;
    }
};