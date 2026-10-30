class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int maxi=0;
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        for(int i=0;i<n;i++){
            int cnt=1;
            int sum=0;
           for(int j=i;j<n;j++){
              sum+=cnt*satisfaction[j];
              cnt++;
           }
           maxi=max(sum,maxi);
        }
        return maxi;
    }
};