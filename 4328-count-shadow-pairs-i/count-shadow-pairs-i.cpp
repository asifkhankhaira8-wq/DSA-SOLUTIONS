class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
         stack<pair<int,int>>st;
         long long ans=0;
         vector<long long>count(n);
         st.push({nums[n-1],n-1});
         for(int i=n-2;i>=0;i--){
          int cnt=0;
          while(!st.empty() && st.top().first>nums[i]){
               st.pop();
          }

           if(!st.empty()) cnt = st.top().second-i-1;
             else cnt =n-i-1;
             count[i]=cnt;
            if(!st.empty() && st.top().first==nums[i]){
                count[i]+=count[st.top().second];
               }
             ans+=count[i];

            st.push({nums[i],i});
         }
        return ans;
    }
};