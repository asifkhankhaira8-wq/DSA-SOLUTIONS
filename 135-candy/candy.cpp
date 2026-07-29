class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        vector<int>peak;
        if(ratings[0]>=ratings[1]) peak.push_back(0);
        
        if(ratings[n-1]>=ratings[n-2]) peak.push_back(n-1);
        int cnt=0;
        for(int i=1;i<n-1;i++){
              if(ratings[i]<ratings[i+1] && ratings[i]<ratings[i-1]){
                cnt++;
              }
         if((ratings[i]>=ratings[i+1] && ratings[i]>=ratings[i-1])){
                peak.push_back(i);
              }
        }
        int ans=0;
        for(int it:peak){
            int l=it-1;
            int cnt=0;
            while(l>=0 && ratings[l]<ratings[l+1]){
                cnt++;
                l--;
            }
            int r=it+1;
            int cnt2=0;
            while(r<n && ratings[r]<ratings[r-1]){
                cnt2++;
                r++;
            }
            ans+=(cnt*(cnt+1)/2)+(cnt2*(cnt2+1)/2);
            ans+=max(cnt,cnt2);
            ans++;
        }
        return ans-cnt;
    }
};