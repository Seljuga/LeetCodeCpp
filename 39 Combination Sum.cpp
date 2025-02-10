class Solution {
private:
    vector<vector<int>> ans;
    vector<int> currentSet;

    void backtrack(vector<int>& candidates, int n, int target) {
        if (target == 0) {
            ans.push_back(currentSet);
            return;
        }
        if (target < 0 || n == candidates.size()) return;
        int size = candidates.size();
        for (int i=n; i<size; i++) {
            currentSet.push_back(candidates[i]);
            backtrack(candidates, i, target - candidates[i]);
            currentSet.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return ans;
    }
};
