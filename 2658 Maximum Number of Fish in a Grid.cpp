class Solution {
private:
    int dfs(vector<vector<int>> & grid, int i, int j, int row, int col) {
        if (i<0 || j<0 || i>=row || j>=col || grid[i][j]==0) return 0;
        int cnt = grid[i][j];
        grid[i][j] = 0;
        cnt += dfs(grid, i-1, j, row, col);
        cnt += dfs(grid, i, j-1, row, col);
        cnt += dfs(grid, i+1, j, row, col);
        cnt += dfs(grid, i, j+1, row, col);
        return cnt;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j]!=0) ans = max(ans, dfs(grid, i, j, row, col));
            }
        }
        return ans;
    }
};
