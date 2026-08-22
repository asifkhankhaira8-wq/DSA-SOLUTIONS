class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows=heights.size();
        int cols=heights[0].size();

        vector<vector<int>>diff(rows,vector<int>(cols,1e9));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});
        
        diff[0][0]=1e9;

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        int maxi=-1e8;
        while(!pq.empty()){

            auto it=pq.top();
            pq.pop();
            auto [x,y]=it.second;
            maxi=max(maxi,it.first);

           if(x==rows-1 && y==cols-1) {
            return maxi;
           }
            for(int i=0;i<4;i++){

               int nx=x+dx[i];
               int ny=y+dy[i];

               if(nx>=0 && nx<rows && ny>=0 && ny<cols){
   
                 int val=abs(heights[x][y]-heights[nx][ny]);

                 if(val<diff[nx][ny]){
                    diff[nx][ny]=val;
                    pq.push({val,{nx,ny}});
                     }
               }
            }
        }
        return 0;
        
    }
};