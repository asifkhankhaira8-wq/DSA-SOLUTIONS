class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int cnt=0;
        while(l<=r){
            if(nums[r]==0){
                r--;
            }
            else if(nums[l]!=0){
                l++;
            }
            else if(nums[l]==0 && nums[r]!=0){
                cnt++;
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
        }
        return cnt;
        
    }
};