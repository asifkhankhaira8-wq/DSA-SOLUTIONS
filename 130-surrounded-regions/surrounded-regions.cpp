class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
             board[i][0]='#';
             q.push({i,0});
             }
            if(board[i][n-1]=='O') {
                board[i][n-1]='#';
                q.push({i,n-1});
            }
        }
          for(int i=1;i<n-1;i++){
            if(board[0][i]=='O') {
            board[0][i]='#';
            q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                 board[m-1][i]='#';
            q.push({m-1,i});}
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<m && nx>=0 && ny<n && ny>=0 && board[nx][ny]=='O'){
                    board[nx][ny]='#';
                    q.push({nx,ny});
                }
            }
            
        }

     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O') board[i][j]='X';
        }
     }
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='#') board[i][j]='O';
        }
     }
    }
};