class Solution {
public:
vector<vector<string>>dp;
bool is_valid(string x,string t){
    return t.find(x) != string::npos;
}
string fun(int l,int h,string s,string t){
 if(l==h) return string(1,s[l]);;
    if(dp[l][h]!=" ") return dp[l][h];
    for(int k=l;k<h;k++){
        string x=fun(l,k,s,t);
        string y=fun(k+1,h,s,t);
        if(x.size()==0 || y.size()==0) continue;
        if(is_valid(x+y,t)){
         return dp[l][h]=x+y;
        }
        else if(is_valid(y+x,t)){
             return dp[l][h]=y+x;
        }
    }
    return dp[l][h]="";
}
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        dp.assign(n+1,vector<string>(n+1," "));
         string a=fun(0,n-1,s1,s2);
         return a==s2;
    }
};