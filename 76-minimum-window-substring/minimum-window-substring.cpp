class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int start=-1;
        for(char ch:t)mp[ch]++;
        int left=0;
        int mini=1e8;
        int cnt=0;
        for(int right=0;right<s.size();right++){
            if(mp[s[right]]>0) cnt++;
            mp[s[right]]--;
            while(cnt==t.size()){
                if(right-left+1<mini){
                    mini=right-left+1;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) cnt--;
                left++;
            }
        }

       return mini ==1e8 ? "" : s.substr(start, mini);

    }
};