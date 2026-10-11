class Solution {
public:
bool contains(vector<string>& wordDict,string temp){
    for(string s:wordDict){
        if(s==temp) return true;
    }
    return false;
}
bool fun(int idx,string s,vector<string>& wordDict,vector<int>&dp){
   if(idx==s.size()) return true;
   if(dp[idx]!=-1) return dp[idx];
   string temp="";
   for(int i=idx;i<s.size();i++){
      temp+=s[i];
      if(contains(wordDict,temp) && fun(i+1,s,wordDict,dp))       return dp[idx]=true;
     }
   return dp[idx]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.size();
      vector<int>dp(n,-1);
      return fun(0,s,wordDict,dp);

    }
};