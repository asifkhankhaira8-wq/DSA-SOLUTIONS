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
    void preorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
         int temp=root->val;
        ans.push_back(temp);
        preorder(root->left,ans);
        preorder(root->right,ans);
     }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
         vector<int>ans;
         stack<TreeNode*>st;
         st.push(root);
         while(!st.empty()){
            TreeNode* top=st.top();
            st.pop();
            ans.push_back(top->val);
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
         }
        return ans;
    }
};