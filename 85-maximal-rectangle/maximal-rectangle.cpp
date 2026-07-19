class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>st;
    int maxi=0;
      for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            int nse=i;
            int idx=st.top();st.pop();
            int pse=st.empty() ? -1 : st.top();
            maxi=max(maxi,(nse-pse-1)*heights[idx]);
        }
        st.push(i);
      }
        while (!st.empty()) {
            int idx=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxi = max(maxi, heights[idx] * (nse - pse - 1));
        }
       return maxi;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
      vector<int>bar(n,0);
      int ans=0;
      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<n;j++){
              if(matrix[i][j]=='1') bar[j]++;
              else bar[j]=0;
        }
        ans=max(largestRectangleArea(bar),ans);
      }
      return ans;
    }
};