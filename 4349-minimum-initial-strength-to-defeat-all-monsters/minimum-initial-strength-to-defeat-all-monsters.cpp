class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> diff(n + 1, 0);
        for(auto it:boosts){
            int l=it[0];
            int r=it[1];
            int w=it[2];
            diff[l]+=w;
            diff[r+1]-=w;
        }
        for(int i=1;i<n;i++) diff[i]+=diff[i-1];
        long long initialStrength = 0;
        long long defeatedStrength = 0;
        for (int i=0;i<n;i++) {
           
            if (monsters[i] > diff[i]) {
                initialStrength = defeatedStrength + monsters[i] - diff[i];
            }
            defeatedStrength += monsters[i];
        }

        return initialStrength;
    }
};