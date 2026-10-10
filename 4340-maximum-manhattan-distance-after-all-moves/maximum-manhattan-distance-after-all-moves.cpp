class Solution {
public:
    int maxDistance(string moves) {
        int ver=0;
        int hor=0;
        int k=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U')  ver++;
            else if(moves[i]=='D') ver--;
            else if(moves[i]=='R') hor++;
            else if(moves[i]=='L') hor--;
            else k++;
        }
        return abs(hor)+abs(ver)+k;
    }
};