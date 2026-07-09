class Solution {
public:
bool fun(int i,int j,int idx,string words,vector<vector<char>>& board,vector<vector<bool>>& vis){
    int n=board.size();
    int m=board[0].size();
    if(idx==words.size()) return true;
     if(j<0 || j>=m || i<0 || i>=n) return false;
     if(vis[i][j]) return false;
    if(board[i][j]!=words[idx])  return false;
    else vis[i][j]=true;
    bool right=fun(i,j+1,idx+1,words,board,vis);
    bool bottom=fun(i+1,j,idx+1,words,board,vis);
    bool left=fun(i,j-1,idx+1,words,board,vis);
    bool up=fun(i-1,j,idx+1,words,board,vis);
    vis[i][j]=false;
    return right || bottom || up || left ;



}
    bool exist(vector<vector<char>>& board, string word) {
            int n=board.size();
           int m=board[0].size();
           vector<vector<bool>> vis(n,vector<bool>(m,false));
             for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(fun(i,j,0,word,board,vis)) return true;
        }
     }
     return false;
    }
};