class Solution {
public:
    vector<int> dp;
    int fun(int n) {
        if (n <= 1) return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;

        for (int root = 1; root <= n; root++) {
            int left = fun(root - 1);
            int right = fun(n - root);

            ans += left * right;
        }

        return dp[n] = ans;
    }

    int numTrees(int n) {
        dp.assign(n + 1, -1);
        return fun(n);
    }
};
