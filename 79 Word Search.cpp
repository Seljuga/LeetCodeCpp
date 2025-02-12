class Solution {
private:
    bool findMatch(vector<vector<char>>& board, string& word, int i, int j, int index) {
        if (index == word.length()) return true;
        int n = board.size(), m = board[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool ans = (
            findMatch(board, word, i+1, j, index+1) ||
            findMatch(board, word, i, j+1, index+1) ||
            findMatch(board, word, i-1, j, index+1) ||
            findMatch(board, word, i, j-1, index+1)
        );
        board[i][j] = temp;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (findMatch(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
