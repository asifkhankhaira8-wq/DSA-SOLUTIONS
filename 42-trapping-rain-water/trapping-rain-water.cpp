class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rightMax(n,0);
       int leftMax = height[0];
        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
             rightMax[i] = max(rightMax[i+1], height[i]);
        int ans=0;
        for(int i=0;i<n;i++){
        //  if(leftMax[i]>height[i] && rightMax[i]>height[i]){
            leftMax= max(leftMax, height[i]);
            ans+=min(leftMax,rightMax[i])-height[i];
        }
    return ans;

    }
};