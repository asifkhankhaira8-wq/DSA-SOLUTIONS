class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        unordered_map<string,int>mp;
        for(string s:bank){
            mp[s]++;
        }
        queue<string>q;
        q.push(startGene);
        int val=-1;
        char dx[4]={'A','C','G','T'};
        while(!q.empty()){
            int sz=q.size();
            val++;
            for(int i=0;i<sz;i++){
                string top=q.front();
                q.pop();
                if(top==endGene) return val;
                string temp=top;
                for(int j=0;j<top.size();j++){
                    for(int k=0;k<4;k++){
                        if(dx[k]!=top[j]){
                             temp[j]=dx[k];
                             if(mp.find(temp)!=mp.end()){
                                q.push(temp);
                                mp.erase(temp);
                              }
                           }
                           temp=top;
                       }
                     }}};

        return -1;
    }
};