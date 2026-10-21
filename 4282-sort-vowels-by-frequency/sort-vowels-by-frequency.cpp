#define pp pair<int, int>

class Solution {
public:
    bool isvowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string sortVowels(string s) {
        int n = s.length();
        unordered_map<char, pp> mp; 

        for (int i = 0; i < n; i++) {
            if (isvowel(s[i])) {
                mp[s[i]].first++;
                if (mp[s[i]].first == 1)
                    mp[s[i]].second = i;
            }
        }

        vector<pair<char, pair<int, int>>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.second.first != b.second.first)
                return a.second.first > b.second.first; 
            return a.second.second < b.second.second;   
        });

        vector<char> ans;
        for (auto& curr : v) {
            for (int j = 0; j < curr.second.first; j++) {
                ans.push_back(curr.first);
            }
        }

        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (isvowel(s[i])) {
                s[i] = ans[idx++];
            }
        }
        return s;
    }
};