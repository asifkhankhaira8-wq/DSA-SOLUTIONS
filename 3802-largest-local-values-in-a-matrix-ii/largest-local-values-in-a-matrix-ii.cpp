class Solution {
public:
       int countLocalMaximums(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int pref[201][201][201] = {0};
        
        for (int val = 0; val <= 200; val++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int add = v[i][j] > val;
                    int up = (i > 0) ? pref[val][i - 1][j] : 0;
                    int left = (j > 0) ? pref[val][i][j - 1] : 0;
                    int diag = (i > 0 && j > 0) ? pref[val][i - 1][j - 1] : 0;
                    
                    pref[val][i][j] = up + left - diag + add;
                }
            }
        }
        
        int ans = 0;
        int dr[4] = {-1, -1, 1, 1}, dc[4] = {-1, 1, -1, 1};
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int x = v[row][col];
                if (x == 0) continue;
                
                int r1 = max(0, row - x), r2 = min(n - 1, row + x);
                int c1 = max(0, col - x), c2 = min(m - 1, col + x);
                
                int total = pref[x][r2][c2];
                int up = (r1 > 0) ? pref[x][r1 - 1][c2] : 0;
                int left = (c1 > 0) ? pref[x][r2][c1 - 1] : 0;
                int diag = (r1 > 0 && c1 > 0) ? pref[x][r1 - 1][c1 - 1] : 0;
                
                int cnt = total - up - left + diag;
                
                for (int t = 0; t < 4; t++) {
                    int nr = row + dr[t] * x, nc = col + dc[t] * x;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] > x) cnt--;
                }
                if (!cnt) ans++;
            }
        }
        return ans;
    }
};