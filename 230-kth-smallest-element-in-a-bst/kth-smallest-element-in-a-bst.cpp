class Solution {
public:
int ans=0;
 void solve(TreeNode* root,int &x,int k){
     if(root==NULL){
            return ;
        }
        solve(root->left,x,k);
        x++;
        if(x==k){
         ans=root->val;
         return; }
        solve(root->right,x,k);
 }
    int kthSmallest(TreeNode* root, int k) {
        int val=0;
        solve(root,val,k);
        return ans;
    }
}; 