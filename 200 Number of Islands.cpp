class Solution {
public:
    int row, col;
    vector<vector<int>> direction = {{1,0},{0,1},{-1,0},{0,-1}};

    void DFS(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (auto & dir : direction) {
            int i_temp = i + dir[0], j_temp = j + dir[1];
            if (i_temp >= 0 && i_temp < row && j_temp >= 0 && j_temp < col && grid[i_temp][j_temp] == '1') {
                DFS(grid, i_temp, j_temp);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        row = grid.size();
        col = grid[0].size();
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++totalIslands;
                }
            }
        }
        return totalIslands;
    }
};
