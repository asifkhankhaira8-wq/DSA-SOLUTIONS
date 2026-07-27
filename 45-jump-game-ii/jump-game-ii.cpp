class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        st.push(n-1);
        int width=1;
        for(int i=n-2;i>=0;i--){
            int top=-1;
            while(!st.empty() && st.top()-i<=nums[i]){
                top=st.top();
                 st.pop();
            }
            if(top!=-1) st.push(top);
            if(nums[i]!=0) st.push(i);
            width++;
        }
        return st.size()-1;
    }
};