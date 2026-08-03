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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int width=-1e8;
        while(!q.empty()){
            int size=q.size();
            long long mini=q.front().second;
            long long l,r;
            for(int i=0;i<size;i++){
                long long top=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) l=top;
                if(i==size-1) r=top;
                if(node->left) q.push({node->left,2*top+1});
                if(node->right) q.push({node->right,2*top+2});

            }
            width=max(width,(int)(r-l+1));
        }
        return width;
    }
};