class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int M=*max_element(nums.begin(),nums.end());
        vector<int>f(M+1);
        for(int i=0;i<=M;i++){
            f[i]=i;
        }
        set<int>st(nums.begin(),nums.end());
  

        for(int a:st){
            if(f[a]==a){
                for(int b=a;b<=M;b+=a){
                    if(f[b]==b){
                        f[b]=a;
                    }
                }
            }
        }
          long long res = 0;
        for (int a : nums) {
            res += f[a];
        }
        return res;
    }
};