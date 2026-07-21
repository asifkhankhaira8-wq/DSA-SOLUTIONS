class Solution {
public:
int solve(vector<int>& nums, int k) {
    int n=nums.size();
        queue<int>q;
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
           if(nums[right]%2!=0) q.push(right);
           if(q.size()>k){
            left=q.front()+1;
              q.pop();
           }
           ans+=right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
     return solve(nums,k)-solve(nums,k-1);
    }
};