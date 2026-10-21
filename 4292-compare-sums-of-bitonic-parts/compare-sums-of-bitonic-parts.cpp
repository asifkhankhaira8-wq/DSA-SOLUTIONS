class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long a_sum=0;
        long long b_sum=0;
        int n=nums.size();
        int i=0;
        while(i<n-1){
            a_sum+=nums[i];
            if(nums[i]>nums[i+1]) {
                break;
            }
            i++;
        }
        while(i<n){
            b_sum+=nums[i];
            i++;
        }
        if(a_sum>b_sum) return 0;
        if(b_sum>a_sum) return 1;

        return -1;
    }
};