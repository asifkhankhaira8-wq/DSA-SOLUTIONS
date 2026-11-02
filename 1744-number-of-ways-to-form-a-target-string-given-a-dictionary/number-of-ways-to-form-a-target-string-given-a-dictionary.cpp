class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<long long>> dp;
    vector<vector<int>> freq;

    int fun(int k, int j, string &target) {
        if(j < 0) return 1;
        if(k < 0) return 0;
        if(j > k) return 0;
        if(dp[k][j] != -1) return dp[k][j];
        long long ways = fun(k-1,j,target);
        int val = freq[k][target[j]-'a'];
        long long take = (1LL * val * fun(k-1,j-1,target)) % MOD;
        ways = (ways + take) % MOD;

        return dp[k][j] = ways;
    }

    int numWays(vector<string>& words, string target) {

        int n = words.size();
        int t = target.size();
        int k = words[0].size();

        freq.assign(k,vector<int>(26,0));

        for(int i=0;i<k;i++) {
            for(int j=0;j<n;j++) {
                freq[i][words[j][i]-'a']++;
            }
        }

        dp.assign(k,vector<long long>(t,-1));

        return fun(k-1,t-1,target);
    }
};