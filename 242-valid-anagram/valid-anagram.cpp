class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
         unordered_map<char,int>mp;
         unordered_map<char,int>mp2;
          for(auto ch:s) mp[ch]++;
          for(auto ch:t) mp2[ch]++;
          for(auto it:mp){
            if(mp2[it.first]!=it.second) return false;
          }

        return true;;
        
    }
};