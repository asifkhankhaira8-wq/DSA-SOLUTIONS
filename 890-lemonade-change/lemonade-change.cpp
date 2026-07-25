class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c1=0;
        int c2=0;
        for(auto it:bills){
            if(it==5)c1++;
            else if(it==10){
                if(c1==0) return false;
                c2++;
                c1--;
            }
            else{
                if(c2>=1 && c1>=1){
                    c2--;
                    c1--;
                }
                else if(c1>=3){
                  c1-=3;
                }
                else return false;
            }
        }
        return true;
    }

};