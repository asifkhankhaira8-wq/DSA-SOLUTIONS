class Solution {
public:
int MOD=1e9+7;
vector<int>primes;
void fun(int n){
    vector<int>isPrime(n+1,true);
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}
    int divisibleGame(vector<int>& nums) {
        int score=0;
        int scoreDifference=0;
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi==1){
            return 1e9+5;
        }
        fun(maxi);
        for(int k:primes){
            int val=nums[0]%k==0 ? nums[0] : -nums[0];
            int bestScore=val;
            int sum=val;
            for(int i=1;i<n;i++){
              val=nums[i]%k==0 ? nums[i] : -nums[i];
              sum=max(val,sum+val);
              bestScore=max(bestScore,sum);
            }
            if(bestScore>scoreDifference){
                scoreDifference=bestScore;
                
                score=(1LL*k*bestScore)%MOD;
            }
        }
       
        return score;
    }
};