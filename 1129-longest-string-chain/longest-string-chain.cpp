class Solution {
public:
void sorting(vector<string>&words){
    sort(words.begin(), words.end(), [](const string& a,const string& b) {
    return a.length() < b.length();
});
}
bool check(string a,string b){
       if(b.size()+1!=a.size()) return false;
  int cnt=0;
  int i=0;
  int j=0;
  while(i<b.size() && j<a.size()){
     if(a[j]!=b[i]){
        j++;
        cnt++;
     }
     else {
    i++;
j++;
}

  }
  return cnt<=1;
}
 int longestStrChain(vector<string>& words) {
       int n=words.size();
       sorting(words);
       vector<int>dp(n,1);

       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          if(check(words[i],words[j])) dp[i]=max(dp[i],1+dp[j]);
}
       }
       return *max_element(dp.begin(),dp.end());
    }
};