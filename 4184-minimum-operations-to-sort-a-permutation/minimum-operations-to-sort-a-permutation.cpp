class Solution {
public:
int mid_point(vector<int>&nums){
   
     int n=nums.size();
     int idx=0;
    for(int i=1;i<n;i++){
        int val= nums[i]-nums[i-1];
        val=abs(val);
        if(val!=1 && val!=n-1)  return -1;
        if(nums[i]==n-1) idx=i;
        }

    return idx;
}
    int minOperations(vector<int>& nums) {
      
       int n=nums.size();
       if(n==1) return 0;
       int point=mid_point(nums);
       if(point==-1) return -1;
       if(point==0) return 1;
       if(point==n-1){
        if(nums[n-1]-nums[n-2]==1) return 0;
        else return 2;
       }
       if(nums[point]-nums[point+1]==n-1){
        return min(point+1,n-point+1);
       }
    
         return min(1+point,n-point+1);
       

    }
};