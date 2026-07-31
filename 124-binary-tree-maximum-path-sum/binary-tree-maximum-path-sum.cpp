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
int ans=-1e8;
int height(TreeNode* root){
         if(root==NULL){
            return 0;
        }
        int opt1=height(root->left);
        int opt2=height(root->right);
         int a=root->val;
         int b=root->val+opt1;
         int c=root->val+opt2;
         int d=root->val+opt1+opt2;
         int temp=max(max(a,b),c);
         ans=max(max(temp,d),ans);
        return temp;

}    
    int maxPathSum(TreeNode* root) {
      height(root);
        return ans;
    }
};