class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum=0;
        for(int i=max((-k+n),0);i<=(k+n);i++){
            if((i&n)==0) {
                sum+=i;
            }
        }
        return sum;
    }
};