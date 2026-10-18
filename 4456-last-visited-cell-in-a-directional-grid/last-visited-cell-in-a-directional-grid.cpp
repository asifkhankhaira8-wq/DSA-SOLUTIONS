class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int x=0;
        int y=0;
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<char,int>mp;
        mp['D']=2;mp['U']=3;mp['R']=0;mp['L']=1;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(true){
           char ch=grid[x][y];
           int nx=x+dx[mp[ch]];
           int ny=y+dy[mp[ch]];
           if(nx==n || nx<0 || ny<0|| ny==m || grid[nx][ny]=='#') break;
           grid[x][y]='#';
           x=nx;
           y=ny;
        }

        return {x,y};
    }
};