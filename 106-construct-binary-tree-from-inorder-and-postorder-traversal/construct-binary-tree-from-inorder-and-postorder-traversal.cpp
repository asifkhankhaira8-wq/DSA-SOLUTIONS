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
TreeNode* fun(int is,int ie,int ps,int pe,vector<int>& postorder, vector<int>& inorder,unordered_map<int,int>&mp){
       if (is>ie || ps>pe) return NULL;
        int rootVal=postorder[pe];
        int idx=mp[rootVal];
        int elem=idx-is;
        TreeNode* root=new TreeNode(rootVal);
        root->left=fun(is,idx-1,ps,ps+elem-1,postorder,inorder,mp);
        root->right=fun(idx+1,ie,ps+elem,pe-1,postorder,inorder,mp);
        return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
     return fun(0,inorder.size()-1,0,postorder.size()-1,postorder, inorder,mp);
    }
};