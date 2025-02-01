class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue;
                for (int k=0; k<9; k++) {
                    if ((board[i][k] == board[i][j] && k!=j) || (board[k][j] == board[i][j] && k!=i)) return false;
                    int row = (i/3)*3 + k/3;
                    int collumn = (j/3)*3 + k%3;
                    if ((board[row][collumn] == board[i][j]) && (row!=i && collumn != j)) return false;
                }
            }
        }
        return true;
    }
};
