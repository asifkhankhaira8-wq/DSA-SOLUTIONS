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
void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &Parent_check){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* top=q.front();
        q.pop();
        if(top->left){
            Parent_check[top->left]=top;
            q.push(top->left);
        }
        if(top->right){
            Parent_check[top->right]=top;
            q.push(top->right);
        }
    }

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*>Parent_check;
        unordered_map<TreeNode*,bool>vis;
        mark_parent(root,Parent_check);
        queue<TreeNode*>q;
        int dist=0;
        q.push(target);
        while(!q.empty()){
            int size=q.size();
            if(dist++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* top=q.front();
                vis[top]=true;
                q.pop();
                 if(top->left && !vis[top->left]){
                 q.push(top->left);
                    }
                if(top->right && !vis[top->right]){
                   q.push(top->right);
                      }
                if(Parent_check[top] && !vis[Parent_check[top]]){
                    q.push(Parent_check[top]);
                }     
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};