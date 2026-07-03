class Solution {
public:
    int romanToInt(string s) {

     int n=0;
    while(!s.empty()){
        char c=s.back();
        if(c=='I') {
            n+=1;
            s.pop_back();}
       else  if(c=='V'){
            if(s.size()>=2 && s[s.size()-2]=='I'){
                n+=4;
                s.pop_back();
            }
            else n+=5;
         s.pop_back(); 
        }
        else if(c=='X'){
            if(s.size()>=2 && s[s.size()-2]=='I'){
                n+=9;
                s.pop_back();
            }
            else n+=10;
          s.pop_back();  
        }
       else if(c=='L'){
            if(s.size()>=2 && s[s.size()-2]=='X'){
                n+=40;
                s.pop_back();
            }
            else n+=50;
          s.pop_back();  
        }
        else if(c=='C'){
            if(s.size()>=2 && s[s.size()-2]=='X'){
                n+=90;
                s.pop_back();
            }
            else n+=100;
          s.pop_back();  
        }
        else if(c=='D'){
            if(s.size()>=2 && s[s.size()-2]=='C'){
                n+=400;
                s.pop_back();
            }
            else n+=500;
          s.pop_back();  
        }
        else if(c=='M'){
            if(s.size()>=2 && s[s.size()-2]=='C'){
                n+=900;
                s.pop_back();
            }
            else n+=1000;
    s.pop_back();
        }
    }
    return n;
        
    }
};