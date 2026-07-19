class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long pattern1=1LL*s +
                             1LL*((n+1)/2-1)*(m-1);

        long long pattern2 = s;
        if (n/2>0) {
            pattern2=1LL* s+m+
                1LL*(n/2-1)*(m-1);
        }

        return max(pattern1, pattern2);
    }
};