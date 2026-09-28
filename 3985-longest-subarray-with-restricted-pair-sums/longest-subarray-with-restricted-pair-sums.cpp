class Solution {
public:
    unordered_map<int, int> mp;

    bool is_valid(int x) {
        for (int k = 1; k <= 500; k++) {
            if (mp.find(k) == mp.end())
                continue;
            int c = k + x;

            if (c <= 500 && mp.find(c) != mp.end()) {
                if (k == x) {
                    if (mp[k] >= 2)
                        return false;
                }
                else {
                    return false;
                }
            }

            if (k < x) {

                int y = x - k;
                if (mp.find(y) != mp.end()) {
                    if (k == y) {
                        if (mp[k] >= 2)
                            return false;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            while (!is_valid(nums[r])) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};