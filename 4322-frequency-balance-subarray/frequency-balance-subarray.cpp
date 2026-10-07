class Solution {
public:
    int getLength(vector<int>& a) {
        int n = a.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;  
            vector<int> fq(n + 1); 
            int mx = 0; 
            int s = 0; 
            for (int j = i; j < n; j++) {
                if (mp[a[j]])
                    fq[mp[a[j]]]--;
                mp[a[j]]++;
                fq[mp[a[j]]]++; 
                if (mp[a[j]] > mx) {
                    mx = mp[a[j]];
                    s = 1; 
                }
                else if (mp[a[j]] == mx) {
                    s++;
                }
                int distinct = mp.size();
                if (distinct == 1) {
                    ans = max(ans, j - i + 1);
                }
                else if (mx % 2 == 0 &&
                         s < distinct &&
                         fq[mx / 2] == distinct - s) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};