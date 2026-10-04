class Solution {
public:
    int minRotations(string s) {
        char prev='0';
        int score=0;
        for(char ch:s){
            score+=min(abs(ch-prev),10-abs(prev-ch));
            prev=ch;
        }
        return score;
    }
};