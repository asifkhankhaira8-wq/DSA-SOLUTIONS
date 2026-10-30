class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int maxi=0;
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int postSum=0,cur=0,res=0;
        for(int i=n-1; i>=0; i--){
            postSum += satisfaction[i];
            cur += postSum;
            res = max(res, cur);
        }
        return res;
    }
};