class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        closest[0] = 1;
        closest[n - 1] = n - 2;
        for (int i = 1; i < n - 1; i++) {
            int left = abs(nums[i] - nums[i - 1]);
            int right = abs(nums[i] - nums[i + 1]);
            if (left <= right)
                closest[i] = i - 1;
            else
                closest[i] = i + 1;
        }
        vector<int> prefix(n);
        prefix[0] = 0;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (closest[i - 1] == i)
                prefix[i]++;
            else
                prefix[i] += abs(nums[i] - nums[i - 1]);
        }
        vector<int> suffix(n);
        suffix[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1];

            if (closest[i + 1] == i)
                suffix[i]++;
            else
                suffix[i] += abs(nums[i] - nums[i + 1]);
        }

        vector<int> ans;

        for (auto &query : queries) {
            int l = query[0];
            int r = query[1];

            if (l <= r)
                ans.push_back(prefix[r] - prefix[l]);
            else
                ans.push_back(suffix[r] - suffix[l]);
        }

        return ans;
    }
};