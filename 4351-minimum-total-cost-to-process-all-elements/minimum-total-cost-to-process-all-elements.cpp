class Solution {
public:
    int MOD = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k) {
        long long cnt = 0;
        long long curr = k;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= curr) {
                curr -= nums[i];
            } else {
                long long val = (nums[i] - curr + k - 1LL) / k;

                cnt += val;

                curr += val * k;
                curr -= nums[i];
            }
        }

        long long ans = cnt % MOD;
        ans = ans * ((cnt + 1) % MOD) % MOD;
        ans = ans * 500000004 % MOD;

        return ans;
    }
};