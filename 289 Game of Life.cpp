class Solution {
private:
    int m, n;
public:
    void bfs(vector<vector<int>>& board, vector<vector<int>>& ans, int row, int col) {
        int count = 0;
        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if (i==0 && j==0) continue;
                int r = row + i;
                int c = col + j;
                if (r>=0 && r<m && c>=0 && c<n) {
                    if (board[r][c]==1) count++;
                }
            }
        }
        if(board[row][col]==1) {
            if(count==2 || count==3) ans[row][col]=1;
        }
        else if(count==3) ans[row][col]=1;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> ans (m, vector<int>(n,0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) bfs(board, ans, i, j);
        }
        board = ans;
    }
};
