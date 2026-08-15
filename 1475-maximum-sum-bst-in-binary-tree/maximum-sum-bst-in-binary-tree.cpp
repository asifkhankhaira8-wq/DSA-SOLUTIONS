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
int  maxi=0;
vector<int> fun(TreeNode* node){
    if(node==NULL) return {true,0,INT_MAX,INT_MIN};
     vector<int> left=fun(node->left);
     vector<int> right=fun(node->right);
     if(left[0] && right[0] && node->val>left[3] && node->val<right[2]){
        maxi=max(maxi,left[1]+right[1]+node->val);
        int mn = min(node->val, left[2]);
        int mx = max(node->val, right[3]);
        return {true,left[1]+right[1]+node->val,mn,mx};
     }
     return {false,0,INT_MIN,INT_MAX};
}
    int maxSumBST(TreeNode* root) {
        fun(root);
        return maxi;
    }
};