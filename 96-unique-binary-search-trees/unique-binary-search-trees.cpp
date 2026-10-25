class Solution {
public:
int fun(int l,int h){
    if(l>h) return 0;
    if(l==h){
      return 1;
    }
    int ans=0;
    for(int k=l;k<=h;k++){
      int left=fun(l,k-1);
      int right=fun(k+1,h);
      if(left!=0 && right!=0 ) ans+=(left*right);
      else{
          ans+=left;
          ans+=right;
      }
    }
    return ans;
}
    int numTrees(int n) {
        return fun(1,n);
    }
};