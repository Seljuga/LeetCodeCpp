class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size();
        int end = size * size;
        vector<bool> visited(end + 1);
        queue<int> queue;
        queue.push(1);
        visited[1] = true;

        int round = 1;
        while (!queue.empty()) {
            int numPos = queue.size();
            for (int i=0; i<numPos; i++) {
                int start = queue.front();
                queue.pop();
                for (int pos=start+1; pos<=start+6; pos++) {
                    int content = getContent(board, pos);
                    int visiting = content == -1 ? pos : content;
                    if (visited[visiting]) continue;
                    if (visiting == end) return round;
                    visited[visiting] = true;
                    queue.push(visiting);
                }
            }
            round++;
        }
        return -1;
    }
    int getContent(vector<vector<int>>& board, int idx) {
        int size = board.size();
        int bottomUpRow = (idx - 1) / size;
        int nonDirectionCol = (idx - 1) % size;
        int row = (size - 1) - bottomUpRow;
        int col = bottomUpRow % 2 == 0 ? nonDirectionCol : (size - 1) - nonDirectionCol;
        return board[row][col];
    }
};
