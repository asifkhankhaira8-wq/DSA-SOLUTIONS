class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int>freq(10,0);
        while(n>0){
            freq[n%10]++;
            n=n/10;
        }
        int ans=0;
        for(int i=1;i<=9;i++){
               ans+=i*freq[i];
        }
        return ans;
        
    }
};