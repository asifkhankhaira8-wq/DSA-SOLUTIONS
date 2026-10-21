class Solution {
public:
    bool validDigit(int n, int x) {
        bool b=false;
        int last=-1;
        while(n>0){
             if(n%10==x) b=true;
             last=n%10;
             n/=10;
        }
        if(last!=x && b) return true;
        return false;
        
    }
};