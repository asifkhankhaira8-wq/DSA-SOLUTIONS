class Solution {
public:
vector<int> nextSmallerElements(vector<int>& arr) {
        // Your code goes here
        stack<int>st;
         int n=arr.size();
        vector<int>ans(n);
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
               ans[i]=n;
            }
            else{
                 ans[i]=st.top();
            }
            st.push(i);
        }
         return ans;}
vector<int> previousSmallerElements(vector<int>& arr) {
        // Your code goes here
         stack<int>st;
         int n=arr.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
               ans[i]=-1;
            }
            else{
                 ans[i]=st.top();
            }
            st.push(i);
        }
         return ans;}
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int>NSE=nextSmallerElements(arr);
        vector<int>PSE=previousSmallerElements(arr);
int ans=0;
         for(int i=0;i<n;i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            ans=(ans+(left*right*1LL*arr[i])%mod)%mod;
         }
         return ans;
    }
};