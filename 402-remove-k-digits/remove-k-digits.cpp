class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char>st;
      int n=num.size();
      int i=0;
      while(i<n){
        while(k>0 && !st.empty() && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
        i++;
      }
    while (k > 0 && !st.empty()) {
    st.pop();
    k--;
    }
      string ans="";
      while(!st.empty()){
        ans+=st.top();
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      i=0;
      while(i<ans.size() && ans[i]=='0'){
        i++;
      }
      ans=ans.substr(i);
      return ans.empty() ? "0":ans;
    }
};