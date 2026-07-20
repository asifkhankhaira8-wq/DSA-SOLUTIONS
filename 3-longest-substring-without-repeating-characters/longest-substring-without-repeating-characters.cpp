class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           if(s.size()==0) return 0;
        unordered_map<char ,int>mp;
        int left = 0;
        int maxi=0;
        for (int i = 0; i < s.size(); i++) {
           if(mp.count(s[i])){
             left=max(left,mp[s[i]]+1);
           }
           mp[s[i]]=i;
                maxi = max(maxi, i-left+1);
        }

        return maxi;
        
    }
};