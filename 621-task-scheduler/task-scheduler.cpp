class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        priority_queue<int>pq;
        unordered_map<char,int>mp;
        for(char ch:tasks){
            mp[ch]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int task=0;
        while(!pq.empty()){
            vector<int>items;
            int n=k+1;
            while(n>0 && !pq.empty()){
                int freq=pq.top();
                freq--;
                 pq.pop();
                 if(freq>0)items.push_back(freq);
                 n--;
                 task++;
            }
             for(auto it:items)pq.push(it);
             if(!pq.empty())   task+=n;
      
        }
        return task;
    }
};