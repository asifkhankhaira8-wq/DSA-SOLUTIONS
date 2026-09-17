class Solution {
public:
    int bfs(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<
            pair<pair<int, pair<int, char>>, pair<int, int>>,
            vector<pair<pair<int, pair<int, char>>, pair<int, int>>>,
            greater<pair<pair<int, pair<int, char>>, pair<int, int>>>
        > pq;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        char dir[4] = {'R', 'L', 'D', 'U'};
        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    k + 1, vector<int>(5, 1e9)
                )
            )
        );

        pq.push({{grid[0][0], {0, '?'}}, {0, 0}});
        dist[0][0][0][0] = grid[0][0];
        while (!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            int cost = top.first.first;
            int turns = top.first.second.first;
            char lastMove = top.first.second.second;

            int x = top.second.first;
            int y = top.second.second;

            int lastDir = 0;

            if (lastMove == 'R') lastDir = 1;
            else if (lastMove == 'L') lastDir = 2;
            else if (lastMove == 'D') lastDir = 3;
            else if (lastMove == 'U') lastDir = 4;

            if (cost != dist[x][y][turns][lastDir])
                continue;

            if (x == m - 1 && y == n - 1)
                return cost;

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 ||
                    nx >= m || ny >= n)
                    continue;

                int newTurns = turns;

                if (lastMove != '?' && dir[i] != lastMove)
                    newTurns++;

                if (newTurns > k)
                    continue;

                int newCost = cost + grid[nx][ny];

                int newDir = i + 1;

                if (newCost < dist[nx][ny][newTurns][newDir]) {

                    dist[nx][ny][newTurns][newDir] = newCost;

                    pq.push({
                        {newCost, {newTurns, dir[i]}},
                        {nx, ny}
                    });
                }
            }
        }

        return -1;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        return bfs(grid, k);
    }
};