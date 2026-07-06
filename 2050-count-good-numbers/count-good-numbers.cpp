class Solution {
public:
    const int MOD = 1000000007;

    int solve(int x, long long n) {
        if (n == 0) return 1;

        long long half = solve(x, n / 2);

        if (n % 2 == 0) {
            return (1LL * half * half) % MOD;
        } else {
            return (1LL * x * ((1LL * half * half) % MOD)) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long oddPosition = n / 2;
        long long evenPosition = (n + 1) / 2;

        return (1LL * solve(4, oddPosition) * solve(5, evenPosition)) % MOD;
    }
};