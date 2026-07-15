class Solution {

public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char y=s[i];
            if(y=='(' || y=='[' || y=='{'){
            st.push(y);
             }
             else{
                if(!st.empty()){
                if( st.top()== '(' && y==')' ||
                  st.top()== '{' && y=='}' ||
                  st.top()== '[' && y==']'){
                 st.pop();
                }
                else 
                  return false;
             }
              else return false;}
    
    }
   if(st.empty()){
   return true;
   }
   else return false;
    }
};