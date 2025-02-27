class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int size = arr.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        vector<vector<int>> dp(size, vector<int>(size, 2));

        for (int i=0; i<size; ++i) {
            mpp[arr[i]] = i;
            for (int j=0; j<i; j++) {
                int val = arr[i] - arr[j];
                if (mpp.find(val) != mpp.end() && mpp[val] < j) dp[i][j] = 1 + dp[j][mpp[val]];
                ans = max(ans, dp[i][j]);
            }
        }
        if (ans == 2) return 0;
        return ans;
    }
};
