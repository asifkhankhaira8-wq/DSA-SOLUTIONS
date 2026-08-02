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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        vector<int>ans;
        q.push({root});
        while(!q.empty()){
          int size=q.size();
          ans.push_back(q.front()->val);
        for(int i=0;i<size;i++){
             TreeNode* top=q.front();
             q.pop();
             if(top->right) q.push(top->right);
             if(top->left) q.push(top->left);
        }
        }
        return ans;
    }
};