class Solution {
    int islandId = 2;
    unordered_map<int, int> areaOfIsland;
    void find(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;
        grid[i][j] = islandId;
        areaOfIsland[islandId]++;
        find(i+1, j, n, m, grid);
        find(i-1, j, n, m, grid);
        find(i, j+1, n, m, grid);
        find(i, j-1, n, m, grid);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==1) {
                    find(i, j, n, m, grid);
                    islandId++;
                }
            }
        }
        int maxI = 0;
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                unordered_map<int, int> visIsland;
                int sum = 0;
                if (grid[i][j] != 0) continue;
                for (auto it : dir) {
                    int x = i + it.first;
                    int y = j + it.second;
                    if (x>=0 && y>=0 && x<n && y<m) {
                        if (visIsland.count(grid[x][y]) || grid[x][y]==0) continue;
                        sum += areaOfIsland[grid[x][y]];
                        visIsland[grid[x][y]] = 1;
                    }
                }
                maxI = max(maxI, sum + 1);
            }
        }
        cout<<islandId;
        for (auto it : areaOfIsland) maxI = max(maxI, it.second);
        return maxI;
    }
};
