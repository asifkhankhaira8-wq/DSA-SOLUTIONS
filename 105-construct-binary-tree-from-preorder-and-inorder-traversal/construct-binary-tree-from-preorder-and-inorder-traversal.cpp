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
int i=0;
TreeNode* fun(int s,int e,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp){
    if (s>e)return NULL;
        int rootVal=preorder[i++];
        int idx=mp[rootVal];
        TreeNode* root=new TreeNode(rootVal);
        root->left=fun(s,idx-1,preorder,inorder,mp);
        root->right=fun(idx+1,e,preorder,inorder,mp);
   
        return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        return fun(0,inorder.size()-1,preorder, inorder,mp);
    }
};