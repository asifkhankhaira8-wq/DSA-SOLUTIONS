class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
        }
        int maxi=sum;
        for(int i=n-k;i<n;i++){
            sum-=cardPoints[i];
            sum+=cardPoints[(i+k)%n];
            maxi=max(sum,maxi);
        }
        return maxi;
        
    }
};