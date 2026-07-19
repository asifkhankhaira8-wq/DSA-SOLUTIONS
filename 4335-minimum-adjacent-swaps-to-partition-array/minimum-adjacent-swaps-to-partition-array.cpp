class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int c1=0,c2=0;
        int res=0;
        int mod=1e9+7;
        for(int it:nums){
            if(it<a){
               res=(res+c1+c2)%mod;
            }
           else if(it<=b  && it >=a) {
            res=(res+c1)%mod;
            c2++;
           }
           else c1++;
        }
        return res;
    }
};