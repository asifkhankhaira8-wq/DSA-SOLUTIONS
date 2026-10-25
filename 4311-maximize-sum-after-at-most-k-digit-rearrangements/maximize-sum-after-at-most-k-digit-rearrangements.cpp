class Solution {
public:
vector<int>arr;
int find_max(int n){
     map<int,int,greater<int>>mp;
     while(n>0){
        int val=n%10;
        mp[val]++;
         n/=10;
     }
     int ans=0;
     for(auto [d,o]:mp){
         while(o>0){
           ans=ans*10+d;
           o--;
         }
     }
     return ans;

}
long long  fun(vector<int>&nums){
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++){
        arr[i]=find_max(nums[i]);
        sum+=nums[i];
    }
    return sum;
}
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        arr.resize(n);
         long long sum=fun(nums);
        for(int i=0;i<n;i++){
            arr[i]=arr[i]-nums[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        return sum;
            }
};