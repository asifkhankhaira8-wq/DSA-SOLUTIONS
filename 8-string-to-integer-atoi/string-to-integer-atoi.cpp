class Solution {
public:
int fun(int i,string s,int sign,long long &num){
        int n = s.size();
        if (i == n)  return 0;
        if(!isdigit(s[i])) return 0;
        int digit = s[i] - '0';
       if (num > (INT_MAX - digit) / 10) {
             return (sign == 1) ? INT_MAX : INT_MIN;
         }
          num=digit+num*10;
        return fun(i+1,s,sign,num);



}
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == ' ')  i++;
        if (i == n)
            return 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        long long num=0;
       
         int val=fun(i,s,sign ,num);
         if(val==INT_MAX || val==INT_MIN) return val;
        return sign *num;
    }
};