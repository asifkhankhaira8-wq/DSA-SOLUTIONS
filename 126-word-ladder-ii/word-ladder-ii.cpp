class Solution {
public:
vector<vector<string>>ans;
string b;
void dfs(int steps,string endWord,vector<string>&vec,unordered_map<string ,int>&mp){
     if(endWord==b){
        reverse(vec.begin(),vec.end());
        ans.push_back(vec);
        reverse(vec.begin(),vec.end());
        return ;
     }

     for(int i=0;i<endWord.size();i++){
        string og=endWord;
        for(char ch='a';ch<='z';ch++){
            endWord[i]=ch;
            if(mp.find(endWord) != mp.end() && mp[endWord] == steps){
                 vec.push_back(endWord);
                dfs(steps-1,endWord,vec,mp);
                vec.pop_back();
            }
        }
        endWord=og;
     }


}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        queue<pair<string , int>>q;
        unordered_map<string ,int>mp;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        mp[beginWord]=1;
        while(!q.empty()){
               string word=q.front().first;
               int step=q.front().second;
               q.pop();
               if(word==endWord) {
                vector<string>seq;
                seq.push_back(endWord);
                dfs(step-1,endWord,seq,mp);
                return ans;
                }
               for(int i=0;i<word.size();i++){
                  char original=word[i];
                  for(char ch='a' ; ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                        mp[word]=step+1;
                    }
                  }
              word[i]=original;
               }
               
        }
        return {};
    }

};