class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=1e9;
        int n=nums.size();
       for(int x=0;x<=k-1;x++){
        for(int y=0;y<=k-1;y++){
            int sum=0;
             if(x == y)    continue;
            for(int i=0;i<n;i++){
                 int a=nums[i]%k;
                  if(i%2==0) {
                 sum+=min((a+(k-x))%k,(x-a+k)%k);
                  }
                  else sum+=min((a+(k-y))%k,(y-a+k)%k); 
            }
            mini=min(mini,sum);
        }
       }
       return mini;
    }
};