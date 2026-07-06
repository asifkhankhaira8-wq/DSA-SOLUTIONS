class Solution {
public:
void fun(int i,int n ,int cnt,string temp,vector<string> &ans){
    if(i==n){
        if(cnt==0) ans.push_back(temp);
        return ;
    }
        if(cnt<0) return ;
        fun(i+1,n,cnt+1,temp+'(',ans);
        fun(i+1,n,cnt-1,temp+')',ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun(0,2*n,0,"",ans);
        return ans;
    }
};