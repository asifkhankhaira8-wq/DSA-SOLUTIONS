class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
       vector<vector<int>>vis(n,vector<int>(n,0));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

       pq.push({grid[0][0],{0,0}});
       vis[0][0]=true;
       int dx[4]={0,0,1,-1};
       int dy[4]={1,-1,0,0};
       int maxi=grid[0][0];
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int wt=it.first;
        int x=it.second.first;
        int y=it.second.second;
         maxi=max(wt,maxi);
        if(x==n-1 && y==n-1){
            return maxi;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]){
                   vis[nx][ny]=true;
                    pq.push({grid[nx][ny],{nx,ny}});
            }
        }

       }
    return maxi;

    }
};