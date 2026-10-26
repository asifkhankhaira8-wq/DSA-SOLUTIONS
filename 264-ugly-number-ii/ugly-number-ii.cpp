class Solution {
public:
int nthUglyNumber(int n) {
    vector<int>nums(n+1);
    int i2=1;
    int i3=1;
    int i5=1;
    nums[1]=1;
    for(int i=2;i<=n;i++){
        int a=nums[i2]*2;
        int b=nums[i3]*3;
        int c=nums[i5]*5;
        int mini=min({a,b,c});
        if(mini==a){
             nums[i]=a;
             i2++;
        }
        if(mini==b){
             nums[i]=b;
             i3++;
        }
        if(mini==c){
             nums[i]=c;
             i5++;
        }
    }
    return nums[n];

}
};