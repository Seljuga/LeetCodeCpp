class Solution {
private:
    void find(int row, int n,vector<string> &board,vector<bool> &col,int &count,vector<bool> &leftDig,vector<bool> &rightDig){
        if (row == n){
            count++;
            return;
        }
        for (int j=0; j<n; j++){
            if (col[j]==0 && leftDig[row+j]==0 && rightDig[n-1+j-row]==0){
                col[j]=1;
                board[row][j]='Q';
                leftDig[row+j]=1;
                rightDig[n-1+j-row]=1;
                find(row+1,n,board,col,count,leftDig,rightDig);
                col[j]=0;
                board[row][j]='.';
                leftDig[row+j]=0;
                rightDig[n-1+j-row]=0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string>board(n);
        int count=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++) board[i].push_back('.');
        }
        vector<bool>leftDig(2*n-1,0);
        vector<bool>rightDig(2*n-1,0);
        vector<bool>col(n,0);
        find(0,n,board,col,count,leftDig,rightDig);
        return count;
    }
};
