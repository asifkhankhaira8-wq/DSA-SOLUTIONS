class Solution {
public:
 int MOD=1e9+7;
string get_string(int n){
    string s=to_string(n);
    if(s.size()==1) s='0'+s;
    string temp=s;
    temp+='.';
    reverse(s.begin(),s.end());
    temp+=s;
    return temp;
}
    long long fun(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j] || t[j]=='.')
      return dp[i][j] = (fun(i - 1, j - 1, s, t, dp)
                            + fun(i-1, j, s, t, dp))%MOD;
        return dp[i][j] = fun(i - 1, j, s, t, dp);
    }
    int countPalindromes(string s) {
        int n=s.size();
      long long ans=0;
        for(int i=0;i<100;i++){
            vector<vector<int>>dp(n,vector<int>(5,-1));
          string t=get_string(i);
          ans=(ans+fun(n-1,4,s,t,dp))%MOD;
        }
        return ans;
    }
};