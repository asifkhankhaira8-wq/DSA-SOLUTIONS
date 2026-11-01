class Solution {
public:
int n,m;
int MOD=1e9+7;
vector<string> pizza;
vector<vector<vector<long long>>>dp;
bool check(int i,int j,int x,int y){
    for(int a=i;a<x;a++){
        for(int b=j;b<y;b++){
           if(pizza[a][b]=='A') return true;
        }
    }
    return false;
}
int fun(int i,int j,int k){
   if(k==0) return check(i,j,n,m) ;

   if(dp[i][j][k]!=-1) return dp[i][j][k];
   long long ways=0;
    // cutting horizontally;
    for(int x=i;x<n-1;x++){
        if(check(i,j,x+1,m) && check(x+1,j,n,m)){
            ways=(ways+fun(x+1,j,k-1))%MOD;
        }
    }
    //cutting vertically;
     for(int x=j;x<m-1;x++){
        if(check(i,j,n,x+1) && check(i,x+1,n,m)){
            ways=(ways+fun(i,x+1,k-1))%MOD;
        }
    }
    return dp[i][j][k]=ways;
}
    int ways(vector<string>& pizza, int k) {
         n=pizza.size();
         m=pizza[0].size();
       this->pizza=pizza;
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(k,-1)));
        return fun(0,0,k-1);
    }
};