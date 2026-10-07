class Solution {
public:
    bool checkGoodInteger(int n) {
        int squareSum=0;
        int digitSum=0;
        while(n>0){
            int val=n%10;
            digitSum+=val;
            squareSum+=val*val;
            n/=10;
        }
        if(squareSum - digitSum >= 50) return true;

        return false;
    }
};