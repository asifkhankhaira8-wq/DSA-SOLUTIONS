class Solution {
public:
vector<int> nextSmallerElement(vector<int>& height){
    int n=height.size();
    stack<int>st;
    vector<int>ans(n);
      for(int i=n-1;i>=0;i--){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
      }
      return ans;
}
vector<int> previousSmallerElement(vector<int>& height){
    int n=height.size();
    stack<int>st;
    vector<int>ans(n);
      for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
       ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int>NSE=nextSmallerElement(heights);
        vector<int>PSE=previousSmallerElement(heights);
        int ans=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int left=NSE[i]-i;
            int right=i-PSE[i];
            ans=max(ans,(left+right-1)*heights[i]);
        }
        return ans;
        
    }
};