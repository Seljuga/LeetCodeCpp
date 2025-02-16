class Solution {
private:
    bool dfs(int idx, int n) {
        if (idx == ans.size()) return true;
        if (ans[idx] != 0) return dfs(idx + 1, n);
        for (int num=n; num>=1; num--) {
            if (used[num]) continue;
            int j = (num == 1) ? idx : idx + num;
            if (j >= ans.size() || ans[j] != 0) continue;
            ans[idx] = ans[j] = num;
            used[num] = true;
            if (dfs(idx + 1, n)) return true;
            ans[idx] = ans[j] = 0;
            used[num] = false;
        }
        return false;
    }
public:
    vector<int> ans;
    vector<bool> used;

    vector<int> constructDistancedSequence(int n) {
        ans.assign(2*n - 1, 0);
        used.assign(n + 1, false);
        dfs(0, n);
        return ans;
    }
};
