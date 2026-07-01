class Solution {
public:
    string reverseWords(string s) {
        //reverse words
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
          if(s[i]!=' '){
            int idx=i+1;
            string temp="";
            temp+=s[i];
            while(idx<n && s[idx]!=' '){
                temp+=s[idx];
                idx++;
            }
            ans=" "+temp+ans;
            i=idx;
          }
        }
        ans.erase(0, 1);
        return ans;
        
    }
};