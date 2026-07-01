class Solution {
public:
    string check(string s1,string s2){
        int i=0;
        int j=0;
        string temp="";
        while(i<s1.size() && j<s2.size()){
             if(s1[i]!=s2[j]) break;
             temp+=s1[i];
             i++;
             j++;
        }
        
         return temp;

    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string common=strs[0];
        for(int i=1;i<n;i++){
          common=check(strs[i],common);
          if(common=="") return "";
        }
        return common;
    }
};