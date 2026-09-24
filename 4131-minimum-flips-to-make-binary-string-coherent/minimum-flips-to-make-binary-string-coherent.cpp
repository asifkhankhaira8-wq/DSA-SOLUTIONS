class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        if (n < 3) return 0;
        int c0 = 0;
        int c1 = 0;

        for (char ch : s) {
            if (ch == '0') c0++;
            else c1++;
        }
        int cost1 = c1;
        int cost2 = c0;
        int cost3 = (c1 == 0 ? 0 : c1 - 1);
        
        int cost4 = INT_MAX;

        if (s.front() == '1' && s.back() == '1') {
            cost4 = c1 - 2;
        }

        return min({cost1, cost2, cost3, cost4});
    }
};