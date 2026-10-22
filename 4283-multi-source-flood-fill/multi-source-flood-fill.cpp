class Solution {
public:
   bool isValid(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
   }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>grid(n,vector<int>(m,0));
        priority_queue<tuple<int,int,int>>pq;
        for(auto it:sources){
            if(it[2]!=0){
                grid[it[0]][it[1]]=it[2];
                pq.push({it[2],it[0],it[1]});
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(true){
            vector<tuple<int,int,int>>val;
            while(!pq.empty()){
                auto [col,x,y]=pq.top();
                pq.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                   if(isValid(nx,ny,n,m) && grid[nx][ny]==0){
                       grid[nx][ny]=col;
                       val.push_back({col,nx,ny});
                   }
                }
            }
            if(val.empty()) break;
            for(auto it:val) pq.push(it);
        }
        return grid;
    }
};