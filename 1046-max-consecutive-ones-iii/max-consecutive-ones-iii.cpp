class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int>q;
        int left=0;
        int right=0;
        int maxi=0;
        while(right<nums.size()){
            if(nums[right] == 0)  q.push(right);
            if(q.size()>k){
              left=q.front()+1;
              q.pop();
                }
           maxi=max(maxi,right-left+1);
          right++;
        }
        return maxi;
    }
};