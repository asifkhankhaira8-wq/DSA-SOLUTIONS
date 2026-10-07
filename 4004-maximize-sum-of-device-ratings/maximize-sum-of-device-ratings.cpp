class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {

        int m = units.size();
        int n = units[0].size();

        vector<long long> secondMin(m);
        vector<long long> firstMin(m);

        for(int i = 0; i < m; i++) {

            long long min1 = 1e18;
            long long min2 = 1e18;

            for(int j = 0; j < n; j++) {

                if(units[i][j] < min1) {
                    min2 = min1;
                    min1 = units[i][j];
                }
                else if(units[i][j] < min2) {
                    min2 = units[i][j];
                }
            }

            firstMin[i] = min1;
            secondMin[i] = min2;
        }

        long long sum = 0;
        long long mini = 1e18;

        for(int i = 0; i < m; i++) {

            if(secondMin[i] != 1e18) {
                sum += secondMin[i];
                mini = min(mini, secondMin[i]);
            }
            else {
                sum += firstMin[i];
                mini = min(mini, firstMin[i]);
            }
        }

        if(mini == 1e18) {

            long long x = 0;

            for(long long it : firstMin)
                x += it;

            return x;
        }

        firstMin.push_back(mini);

        return sum - mini +
               *min_element(firstMin.begin(), firstMin.end());
    }
};