class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int cnt=0;
        int n=0;
        for(char ch:s){
         if(ch=='('){
            n++;
         }
         else if(ch==')'){
            maxi=max(maxi,(n-cnt));
            cnt++;
         }
        }
        return maxi;
    }
};