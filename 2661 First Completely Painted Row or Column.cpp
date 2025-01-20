class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pair<int, int>> map;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) map[mat[i][j]] = {i, j};
        }
        vector<int> freq_row(n, 0);
        vector<int> freq_col(m, 0);
        int ans = -1, size = arr.size();
        for (int i=0; i<size; i++) {
            int idx_row = map[arr[i]].first;
            int idx_col = map[arr[i]].second;
            freq_row[idx_row]++;
            freq_col[idx_col]++;
            if (freq_row[idx_row] == m || freq_col[idx_col] == n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
