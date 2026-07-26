class Solution {
public:
    bool canJump(vector<int>& nums) { 
        int i=nums.size()-1;
       while(i>=1){
        int width=1;
        int idx=i-1;
        while(nums[idx]<width){
             idx--;
             width++;
             if(idx<0) return false;
        }
        i=idx;
       }
       return true;
    }
};