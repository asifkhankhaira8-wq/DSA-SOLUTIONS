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
     void Inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return ;
        }
         int temp=root->val;
        Inorder(root->left,ans);
        ans.push_back(temp);
        Inorder(root->right,ans);
     }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>Inorder;
        stack<TreeNode*>st;
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
               if(st.empty()) break;
               TreeNode* top=st.top();
               st.pop();
               Inorder.push_back(top->val);
               root=top->right;
            }
           
        }
        return Inorder;
    }
};