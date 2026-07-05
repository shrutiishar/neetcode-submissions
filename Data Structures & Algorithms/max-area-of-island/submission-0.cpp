class Solution {
public:
    int count;

    void helper(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {

        vis[i][j] = 1;
        count++;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {

            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < grid.size() &&
                nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1 &&
                vis[nr][nc] == 0) {

                helper(grid, vis, nr, nc);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && vis[i][j] == 0) {

                    count = 0;          
                    helper(grid, vis, i, j);

                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};