class Solution {
public:
    int minRotations(int n, string s) {
          char prev='0';
          int score=0;
        vector<int>prefix(n);
        vector<int>suffix(n);
        for(int i=0;i<n;i++){
           char ch=s[i];
            score+=min(abs(ch-prev),10-abs(prev-ch));
            prev=ch;
            prefix[i]=score;
        }
        score=0;
        prev=s[n-1];
        for(int i=n-2;i>=0;i--){
            char ch=s[i];
            score+=min(abs(ch-prev),10-abs(prev-ch));
            prev=ch;
            suffix[i]=score;
        }
        int val=min(abs('0'-s[n-1]),10-abs('0'-s[n-1]));
        int mini=min(val+suffix[0],prefix[n-1]);
        for(int i=0;i<n-1;i++){
             int val=suffix[i+1]+prefix[i]+min(abs(s[i]-s[n-1]),10-abs(s[i]-s[n-1]));
             mini=min(val,mini);
        }
       return mini;
    }
};