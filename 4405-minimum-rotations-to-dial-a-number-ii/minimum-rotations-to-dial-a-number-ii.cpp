class Solution {
public:
    int minRotations(int n, string s) {
       char prev='0';
        int score=0;
        int maxi=0;
        for(char ch:s){
            int val=min(abs(ch-prev),10-abs(prev-ch));
            score+=val;
            int x=min(abs(prev-s[n-1]),10-abs(prev-s[n-1]));
            maxi=max(val-x,maxi);
            prev=ch;
        }
        return min(score,score-maxi);
    }
};