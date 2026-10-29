class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int i=0;
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]= (s[0]=='1');
        suffix[n-1]= (s[n-1]=='0');
        for(int i=1;i<n;i++) prefix[i]= (s[i]=='1') + prefix[i-1];
        for(int i=n-2;i>=0;i--) suffix[i]= (s[i]=='0') + suffix[i+1];
        int mini=min(suffix[0],prefix[n-1]);
        for(int i=0;i<n-1;i++){
            mini=min(mini,prefix[i]+suffix[i+1]);
        }
        return mini;
        

    }
};