class Solution {
public:
vector<vector<char>>list;
void fun(int i,int last,int sum,int k,vector<char>&temp){
    if(sum>k)  return ;
     if(i<0){
        list.push_back(temp);
        return ;
   }
    if(!last) {
        temp.push_back('1');
        fun(i-1,1,sum+i,k,temp);
        temp.pop_back();
    }
    temp.push_back('0');
    fun(i-1,0,sum,k,temp);
    temp.pop_back();
    return;
}
    vector<string> generateValidStrings(int n, int k) {
        vector<char>temp;
        fun(n-1,0,0,k,temp);
        vector<string> ans;
        for(auto it:list){
            string s;
            reverse(it.begin(),it.end());
            for(char ch:it){
                 s+=ch;
            }
            ans.push_back(s);
        }
        return ans;
    }
};