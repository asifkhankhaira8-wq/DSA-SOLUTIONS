class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        right=0
        left=0
        maxi=0
        dic={}
        while right<len(s):
            dic[s[right]]=dic.get(s[right],0)+1
            while dic[s[right]]>1:
                 dic[s[left]]-=1
                 left+=1
              
            maxi=max(maxi,right-left+1)
            right+=1  

        return maxi    

        