class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty() || asteroids[i]<0){
                st.push(asteroids[i]);
                continue;
            }
            while(!st.empty() && st.top()<0 && abs(st.top())<asteroids[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else if(st.top()<0 && abs(st.top())==asteroids[i]) st.pop();
            else if(st.top()>0){
               st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};