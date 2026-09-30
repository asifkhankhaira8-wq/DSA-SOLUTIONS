class Solution {
public:
    int passwordStrength(string password) {
        set<char>st;
        for(char it:password){
            st.insert(it);
        }
        int points=0;
        for(char ch:st){
            if(ch>='a' && ch<='z') points++;
            else if(ch>='A' && ch<='Z') points+=2;
            else if(ch>='0' && ch<='9' )points+=3;
            else points+=5;
        }
        return points;
    }
};