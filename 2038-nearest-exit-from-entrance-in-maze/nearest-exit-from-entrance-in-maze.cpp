class Solution {
public:
int n,m;
bool valid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>>q;
        grid[entrance[0]][entrance[1]]='+';
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=entrance[0]+dx[i];
            int ny=entrance[1]+dy[i];
            if(valid(nx,ny) && grid[nx][ny]=='.'){
                grid[nx][ny]='+';
                  q.push({nx,ny});
            }
        }
        int val=1;
        while(!q.empty()){
           int sz=q.size();
           while(sz--){
              auto [x,y]=q.front();
              q.pop();
              for(int i=0;i<4;i++){
              int nx=x+dx[i];
              int ny=y+dy[i];
              if(nx<0 || ny<0 || nx>=n || ny>=m) return val;
            if(valid(nx,ny) && grid[nx][ny]=='.'){
                  grid[nx][ny]='+';
                  q.push({nx,ny});
            }
        }
           }
           val++;
        }
        return -1;
    }
};