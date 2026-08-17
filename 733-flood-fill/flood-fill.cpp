class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color) return image;
        int startColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
        
            for(int i=0;i<4;i++){
                int nx=it.first+dx[i];
                int ny=it.second +dy[i];
                if(nx<m && nx>=0 && ny<n && ny>=0 && image[nx][ny]==startColor){
                        image[nx][ny]=color;
                    q.push({nx,ny});
                } 
            
            }
        }
        return image;

    }
};