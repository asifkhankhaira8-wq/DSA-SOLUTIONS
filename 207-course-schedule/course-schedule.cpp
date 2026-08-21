class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        vector<int>indegree(numCourses);
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            for(int it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
         int top=q.front();
         q.pop();
            ans.push_back(top);
            for(int it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans.size()==numCourses;
    }
};