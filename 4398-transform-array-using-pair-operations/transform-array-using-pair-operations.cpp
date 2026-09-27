class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1=0;
        long long sum=0;
        for(int it:target){
            sum+=it;
        }
        for(int it:source){
            sum1+=it;
        } 
        if(sum1!=sum) return false;
        return true;
    }
};