class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
       deque<int>q;
        int left=0;
        int right=0;
        vector<int>ans;
        while(right<n){
            while(!q.empty() && nums[q.back()]<nums[right]){
                q.pop_back();
            }
            q.push_back(right);
            if(right-left==k-1){
                ans.push_back(nums[q.front()]);
                if(left==q.front()) q.pop_front();
                left++;
            }
            right++;
        }
        return ans;

    }
};