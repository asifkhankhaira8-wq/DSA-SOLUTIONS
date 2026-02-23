class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        dic = {}
        maxi = 0

        for right in range(len(s)):

            dic[s[right]] = dic.get(s[right], 0) + 1

            while (right - left + 1) - max(dic.values()) > k:
                dic[s[left]] -= 1
                left += 1

            maxi = max(maxi, right - left + 1)

        return maxi
