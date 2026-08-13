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
 TreeNode* fun(int low,int high,vector<int>& preorder){
    if(low>high) return NULL;
    
    TreeNode* node=new TreeNode(preorder[low]);
    int idx=-1;
    for(int i=low+1;i<=high;i++){
      if(preorder[i]>node->val){
        idx=i;
        break;
      }
    }
    if(idx==-1){
        idx=high+1;
    }
    node->left=fun(low+1,idx-1,preorder);
    node->right=fun(idx,high,preorder);
    return node;
 }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return fun(0,preorder.size()-1,preorder);
    }
};