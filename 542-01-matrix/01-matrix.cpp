class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                      int nx=i+dx[k];
                      int ny=j+dy[k];
                      if(nx<m && nx>=0 && ny<n && ny>=0 && mat[nx][ny]==1 && !vis[nx][ny]){
                        vis[nx][ny]=true;
                        q.push({nx,ny});

                      }
                    }
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                 for(int k=0;k<4;k++){
                      int nx=it.first+dx[k];
                      int ny=it.second+dy[k];
                      if(nx<m && nx>=0 && ny<n && ny>=0 && mat[nx][ny]==1 && !vis[nx][ny]){
                        vis[nx][ny]=true;
                        mat[nx][ny]=mat[it.first][it.second]+1;
                        q.push({nx,ny});
                      }}
            }
        }
        return mat;
        
    }
};