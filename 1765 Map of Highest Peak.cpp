class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    que.push({i, j});
                }
            }
        }
        while(!que.empty()) {
            int N = que.size();
            while (N--) {
                auto p = que.front();
                que.pop();
                int i = p.first, j = p.second;
                for (auto &d : dir) {
                    int new_i = i + d[0], new_j = j + d[1];
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && height[new_i][new_j] == -1) {
                        height[new_i][new_j] = height[i][j] + 1;
                        que.push({new_i, new_j});
                    }
                }
            }
        }
        return height;
    }
};
