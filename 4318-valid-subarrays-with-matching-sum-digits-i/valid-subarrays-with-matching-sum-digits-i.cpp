class Solution {
public:
int fun(long long sum,int x){
    if(sum<=9){
        if(sum==x) return true;
        return false;
    }
    int first=sum%10;
    while(sum>9){
        sum/=10;
    }
    int second=sum;
    return first==x && second==x;
}
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
          long long sum=0;
          for(int j=i;j<n;j++){
              sum+=nums[j];
              if(fun(sum,x)) cnt++;
            }
        }
        return cnt;
    }
};