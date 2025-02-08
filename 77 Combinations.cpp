class Solution {
private:
    vector<vector<int>> ans;
    vector<int> currentSet;
    int maxN, maxK;

    void backTrack(int n) {
        if (maxK == currentSet.size()) {
            ans.push_back(currentSet);
            return;
        }
        for (int i=n; i<maxN; i++) {
            currentSet.push_back(i);
            backTrack(i+1);
            currentSet.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        maxN = n + 1;
        maxK = k;
        backTrack(1);
        return ans;
    }
};
