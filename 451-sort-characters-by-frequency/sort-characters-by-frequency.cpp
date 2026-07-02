class Solution {
public:
    string frequencySort(string s) {
        //using bucket sort
       int n=s.size();
        vector<vector<char>>bucket(n+1);
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(auto it:mp){
         bucket[it.second].push_back(it.first);
        }
        string ans="";
        for(int i=n;i>=0;i--){
              for(char it:bucket[i]) {
                for(int j=0;j<i;j++) ans+=it;}
        }
        return ans;
    }
};