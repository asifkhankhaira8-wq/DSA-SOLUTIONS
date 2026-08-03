/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
 TreeNode* ans;
bool fun(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL) return false;
    bool itself=false;
    if(root==p || root==q){
         itself=true;
    }
    bool left= fun(root->left,p,q);
    bool right=fun(root->right,p,q);
    if((left && right) || (left && itself) || (right && itself)){
        ans=root;
        return true;
    }
    return right || left || itself;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root,p,q);
        return ans;
    }
};