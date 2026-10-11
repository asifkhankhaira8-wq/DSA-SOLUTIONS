class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
int n = s.size();
 unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[n] = true;
    for (int idx = n - 1; idx >= 0; idx--) {
        string temp = "";
        for (int i = idx; i < n; i++) {
            temp += s[i];
            if (dict.count(temp) && dp[i + 1]) {
                dp[idx] = true;
                break;
            }
        }
    }

    return dp[0];
}

};
