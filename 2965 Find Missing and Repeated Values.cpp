class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) {
            return {};
        }
        int col = grid[0].size();

        long long actualSum = 0, actualSquareSum = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                actualSum += grid[r][c];
                actualSquareSum += grid[r][c] * grid[r][c];
            }
        }

        int x = row * row;
        long long expectedSum = (x * (x + 1LL)) / 2;
        long long expectedSquareSum = (x * (x + 1LL) * (2LL * x + 1)) / 6;

        long long sumDiff = expectedSum - actualSum;
        long long squareSumDiff = expectedSquareSum - actualSquareSum;

        long long sumOfMissingAndRepeating = squareSumDiff / sumDiff;

        int missing = (sumDiff + sumOfMissingAndRepeating) / 2;
        int repeating = missing - sumDiff;

        return {repeating, missing};
    }
};
