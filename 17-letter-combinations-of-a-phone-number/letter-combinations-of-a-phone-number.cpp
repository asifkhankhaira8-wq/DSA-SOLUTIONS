class Solution {
public:
void fun(int i,string digits,string &temp,vector<string> &ans,vector<string> &letters){
    if(i==digits.size()){
        ans.push_back(temp);
        return;
    }
    int digit=digits[i]-'0';
     for(char ch:letters[digit]){
        temp+=ch;
        fun(i+1,digits,temp,ans,letters);
        temp.pop_back();
     }
}
    vector<string> letterCombinations(string digits) {
       vector<string>letters(10,"");
       letters[2]="abc";
       letters[3]="def";
       letters[4]="ghi";
       letters[5]="jkl";
       letters[6]="mno";
       letters[7]="pqrs";
       letters[8]="tuv";
       letters[9]="wxyz";
       vector<string> ans;
       string temp="";
       fun(0,digits,temp,ans,letters);
       return ans;
    }
};