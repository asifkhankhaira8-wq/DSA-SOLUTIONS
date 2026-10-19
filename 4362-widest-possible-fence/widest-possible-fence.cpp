class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long, int> freq;
        unordered_map<long long, int> pairs;
        for (int x : planks) {
            freq[x]++;
        }
        vector<long long> vals;
        for (auto& [x, count] : freq) {
            vals.push_back(x);
        }
        int k = vals.size();
        int maxi = 1;
        for (auto& [x, count] : freq) {
            maxi = max(maxi, count);
        }
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                long long target = vals[i] + vals[j];
                int count;
                if (i == j) {
                    count = freq[vals[i]] / 2;
                } else {
                    count = min(freq[vals[i]], freq[vals[j]]);
                }
                pairs[target] += count;
            }
        }
        for (auto& [target, count] : pairs) {
            maxi = max(maxi, count + freq[target]);
        }
        return maxi;
    }
};