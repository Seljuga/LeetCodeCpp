class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        int size = prerequisites.size();
        for (int i=0; i<size; i++) adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int> ans;
        vector<int> inDegree(n, 0);
        for (int u=0; u<n; u++) {
            for (auto v : adj[u]) inDegree[v]++;
        }

        queue<int> q;
        for (int u=0; u<n; u++) {
            if (inDegree[u] == 0) q.push(u);
        }
        int cnt = 0;
        while(!q.empty()) {
            int u = q.front();
            cnt++;
            ans.push_back(u);
            q.pop();

            for (auto v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
        }
        if (cnt != n) return {};
        return ans;
    }
};
