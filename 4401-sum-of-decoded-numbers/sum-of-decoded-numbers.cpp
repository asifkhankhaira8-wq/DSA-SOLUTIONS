class Solution {
public:
long long mod=1e9+7;
long long power(long long x,long long y){
        long long ans=1;
        while(y>0){
            if(y%2)
                ans=(1LL*ans*x)%mod;
            x=(1LL*x*x)%mod;
            y/=2;
        }
        return ans;
    }
long long fun(long long n){
    int width=n%10;
    n/=10;
    vector<int>nums;
    while(n>0){
        nums.push_back(n%10);
        n/=10;
    }
    reverse(nums.begin(),nums.end());
    long long x=0;
    long long y=0;
    for(int i=0;i<width ;i++){
        x*=10;
        x+=nums[i];
    }
    for(int i=width;i<nums.size();i++){
        y*=10;
        y+=nums[i];
    }

    return power(x,y)%mod;

}
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
             ans=(ans+fun(nums[i]))%mod;
        }
        return ans;
        
    }
};