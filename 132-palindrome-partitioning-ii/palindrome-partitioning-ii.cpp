class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int fun(int i,string &s,vector<int>&dp){
    int n=s.size();
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
     int mini=INT_MAX;
    for(int k=i;k<n;k++){
        if(isPalindrome(i,k,s)){
        int val=1+fun(k+1,s,dp);
        mini=min(val,mini);
       }
    }
    return dp[i]=mini;
}
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return fun(0,s,dp)-1;        
    }
};