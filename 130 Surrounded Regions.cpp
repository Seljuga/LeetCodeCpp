class Solution {
public:
    void bfs(vector<vector<bool>> &visited, vector<vector<char>>& board, int row, int col, int a, int b) {
        bool isEdge = false;
        vector<pair<int, int>> regions;
        queue<pair<int, int>> q;
        q.push({a, b});

        while(q.empty() == false) {
            int i = q.front().first, j = q.front().second;
            
            if (i==0 || i==row-1 || j==0 || j==col-1) isEdge = true;
            else {
                regions.push_back({i, j});
                if (visited[i][j] == false) {
                    visited[i][j] = true;
                    if (i-1 >= 0 && board[i-1][j] == 'O') q.push({i-1, j});
                    if (i+1 < row && board[i+1][j] == 'O') q.push({i+1, j});
                    if (j-1 >= 0 && board[i][j-1] == 'O') q.push({i, j-1});
                    if (j+1 < col && board[i][j+1] == 'O') q.push({i, j+1});
                }
            }
            q.pop();
        }
        if (!isEdge) {
            for (int i=0; i<regions.size(); i++) {
                int x = regions[i].first, y = regions[i].second;
                board[x][y] = 'X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<bool>> visited;
        vector<bool> temp(col, false);

        for (int i=0; i<row; i++) visited.push_back(temp);
        for (int i=1; i<row-1; i++) {
            for (int j=1; j<col-1; j++) {
                if (board[i][j] == 'O' && visited[i][j] == false) bfs(visited, board, row, col, i, j);
            }
        }
    }
};
