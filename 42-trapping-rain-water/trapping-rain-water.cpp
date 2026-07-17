class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(left<right){
            lmax=max(height[left],lmax);
            rmax=max(rmax,height[right]);
            if(lmax<rmax){
                ans+=lmax-height[left];
                left++;
            }
            else{
                 ans+=rmax-height[right];
                right--;
            }
        }
        return ans;
    }
};