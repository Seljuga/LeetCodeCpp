class Solution {
private:
    void floyedWarshall(int n, vector<vector<long long>>& warshall) {
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    warshall[i][j] = min(warshall[i][j], warshall[i][k] + warshall[k][j]);
                }
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses, p_size = prerequisites.size(), q_size = queries.size();
        vector<vector<long long>> warshall(n, vector<long long> (n, 2e9+7));
        for (int i=0; i<p_size; i++) warshall[prerequisites[i][0]][prerequisites[i][1]] = 1;
        floyedWarshall(n, warshall);
        vector<bool> ans;
        for (int i=0; i<q_size; i++) {
            if (warshall[queries[i][0]][queries[i][1]]!=2e9+7) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
