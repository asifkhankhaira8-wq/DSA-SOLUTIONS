class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           if(s.size()==0) return 0;
        unordered_map<char ,int>mp;
        int left = 0;
        int maxi=0;
        for (int i = 0; i < s.size(); i++) {
            while (mp[s[i]]>0) {
                mp[s[left]]--;
                left++;
            }
            mp[s[i]]++;
                maxi = max(maxi, i-left);
        }

        return maxi+1;
        
    }
};