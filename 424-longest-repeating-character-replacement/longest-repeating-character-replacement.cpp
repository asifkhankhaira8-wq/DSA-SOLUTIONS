class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int left=0;
        unordered_map<char,int>mp;
        int sz=0;
        int maxi=0;
        for(int right=0;right<n;right++){
           mp[s[right]]++;
           sz=max(sz,mp[s[right]]);
           while(mp.size()>k+1 || ((right-left+1)-sz)>k){
            mp[s[left]]--;
            if(mp[s[left]]==0) {
                mp.erase(s[left]);
            }
            left++;
           }
           maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};