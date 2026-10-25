class Solution {
public:
    map<pair<int, int>, vector<TreeNode*>> dp;

    vector<TreeNode*> fun(int l, int h) {
        if (l > h) return {nullptr};
        if(l==h){
            TreeNode* node=new TreeNode(l);
            return {node};
        }

        auto key = make_pair(l, h);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        vector<TreeNode*> ans;

        for (int k = l; k <= h; k++) {
            vector<TreeNode*> leftTrees = fun(l, k - 1);
            vector<TreeNode*> rightTrees = fun(k + 1, h);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* node = new TreeNode(k);
                    node->left = left;
                    node->right = right;

                    ans.push_back(node);
                }
            }
        }

        return dp[key] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        dp.clear();
        return fun(1, n);
    }
};
//TC---> O(n*(4^n)/(n^1.5))