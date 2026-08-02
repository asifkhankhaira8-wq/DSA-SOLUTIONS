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
bool check(vector<pair<int,int>>&temp){
    if(temp.size()%2!=0) return true;
    int l=0;
    int r=temp.size()-1;
    while(l<=r){
        if(temp[l].first==temp[r].first && temp[l].second==-temp[r].second){
            l++;
            r--;
        }
        else return true;
    }
    return false;
}
    bool isSymmetric(TreeNode* root) {
         if(root==NULL) return true;;
    	//your code goes here
        bool b=true;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            vector<pair<int,int>>temp;
            for(int i=0;i<size;i++){
              auto top=q.front();
              temp.push_back({top.first->val,top.second});
              q.pop();
             if(top.first->left)  q.push({top.first->left,top.second-1});
             if(top.first->right)  q.push({top.first->right,top.second+1});
        }
        if(b) {
            b=!b;
            continue;}
        if(check(temp)) return false;
        }
     
        return true;
        
    }
};