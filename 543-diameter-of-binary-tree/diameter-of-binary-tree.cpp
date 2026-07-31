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
int ans=0;
int height(TreeNode* root){
         if(root==NULL){
            return 0;
        }
        int opt1=height(root->left);
        int opt2=height(root->right);
         ans =max(opt1+opt2,ans);
        return 1+max(opt1,opt2);
}    
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
        return ans;
        
    }
};