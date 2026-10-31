class Solution {
public:
unordered_map<string,bool>mp;
bool fun(string s,string t){
      if(s==t) return true;
      string key=s+"-"+t;
      if(mp.find(key)!=mp.end()) return mp[key];
      bool result=false;
      int n=s.size();
      for(int i=1;i<n;i++){
          bool not_swapped=fun(s.substr(0,i),t.substr(0,i)) && fun(s.substr(i,n-i),t.substr(i,n-i));
          bool swapped=fun(s.substr(0,i),t.substr(n-i,i)) && fun(s.substr(i,n-i),t.substr(0,n-i));
          if(swapped || not_swapped) {
            result=true;
            break;
      }}
    return mp[key]=result;
}
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        return fun(s1,s2);
    }
};