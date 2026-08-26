class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int islands {};

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for(int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    islands++;

                    visited[row][col] = true;
                    q.push({row, col});

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];

                            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1' && !visited[nx][ny]) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }

            }
        }
        return islands;
    }
};
