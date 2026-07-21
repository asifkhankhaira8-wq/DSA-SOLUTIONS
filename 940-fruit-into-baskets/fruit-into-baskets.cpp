class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int right=0;
        int n=fruits.size();
        int x=-1;
        int y=-1;
        int maxi=0;
        vector<int>v(n,0);
        while(right<n){
             if(fruits[right]==x || x==-1){
                v[fruits[right]]++;
                x=fruits[right];
             }
            else if(fruits[right]==y || y==-1){
                v[fruits[right]]++;
                y=fruits[right];
             }
             else {
                while(v[x]>0 && v[y]>0){
                    if(fruits[left]==x) v[x]--;
                    if(fruits[left]==y) v[y]--;
                    left++;
                }
                    if(v[x]==0) x=fruits[right];
                    if(v[y]==0) y=fruits[right];
                    v[fruits[right]]++;
             }
             maxi=max(maxi,right-left+1);
             right++;
        }
        return maxi;
        
    }
};