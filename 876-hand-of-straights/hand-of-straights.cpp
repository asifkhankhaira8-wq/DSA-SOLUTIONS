class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         int k =groupSize;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         if(hand.size()%k!=0) return false;
         if(k==1) return true;
         unordered_map<int,int>mp;
         for(auto it:hand){
            mp[it]++;
         }
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        while(!pq.empty()){
           int count=k-1;
           vector<pair<int,int>>vec;
           auto prev=pq.top();
           pq.pop();
           prev.second--;
           if(prev.second>0) vec.push_back(prev);
           while(count>0 && !pq.empty()){
                  auto top=pq.top();
                  pq.pop();
                  if(top.first!=prev.first+1) return false;
                  top.second--;
                  if(top.second>0)vec.push_back(top);
                  count--;
                  prev=top;
           }
           if(count>0) return false;
           for(auto it:vec){
            pq.push(it);
           }
        }
        return true;
    }
};