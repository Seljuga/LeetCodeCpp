class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>> >> pq;
        int row = heightMap.size();
        int col = heightMap[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (i==0 || i==row-1 || j==0 || j==col-1) {pq.push({heightMap[i][j], {i, j}}); vis[i][j]=1;}
            }
        }
        int l = 0;
        int dx [] = {0, 1, -1, 0};
        int dy [] = {1, 0, 0, -1};
        while (!pq.empty()) {
            pair<int,pair<int,int>> f = pq.top();
            pq.pop();
            int h = f.first;
            l = max(l, h);
            int x = f.second.first;
            int y = f.second.second;
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && vis[nx][ny]==0) {
                    if (heightMap[nx][ny] < l) ans += (l-heightMap[nx][ny]);
                    pq.push({heightMap[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        return ans;
    }
};
