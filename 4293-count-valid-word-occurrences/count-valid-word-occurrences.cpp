class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string ,int>mp;
        int n=chunks.size();
         string s;
        for(int i=0;i<n;i++){
            s+=chunks[i];
        }
        string temp;
        for(int i=0;i<s.size();i++){
               if(s[i]>='a' && s[i]<='z'){
                temp+=s[i];
               }
               else if(s[i]=='-' && i>0 && i+1<s.size() && s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z'){
                temp+=s[i];
               }
               else {
                  if(!temp.empty()) {
                    mp[temp]++;
                    temp = "";
                }
               }
             }
              if (!temp.empty()) {
            mp[temp]++;
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=mp[queries[i]];
        }
        return ans;
    }
};