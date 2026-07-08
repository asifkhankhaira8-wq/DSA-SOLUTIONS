class Solution {
public:
void fun(int k,int n,vector<int>&temp,vector<vector<int>>&ans,int last){
    if(k==0){
       if(n==0){
        ans.push_back(temp);
      }
        return;
    }

        for(int j=last+1;j<=9;j++){
            if(j>n) break;
            temp.push_back(j);
             fun(k-1,n-j,temp,ans,j);
             temp.pop_back();
    }
}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        fun(k,n,temp,ans,0);
        return ans;
    }
};