class Solution {
public:
vector<vector<int>>intervals;
void making_intervals(string s,int index){
    int n=s.size();
    int i=index;
     while(i<n){
          int idx=i;
          while(idx<n && s[idx]=='1') idx++;

          if(idx>i) {
            int l=i-1;
             intervals.push_back({l,idx});
             i=idx+1;
           }  
           else i++;
     }
}
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        if(nums.size()==1) {
            if(s[0]=='1') return nums[0];
            return 0;
        }
        int index=0;
        long long ans=0;
        while(index<n && s[index]=='1'){
             ans+=nums[index];
             index++;
        }
        making_intervals(s,index);
        for(auto it:intervals){
            int mini=1e9;
            for(int i=it[0];i<it[1];i++){
                ans+=nums[i];
                mini=min(mini,nums[i]);
            }
            ans-=mini;
        }
        return ans;
    }
};