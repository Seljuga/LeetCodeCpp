class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> que;

        for (auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) que.push(i);
        }
        int count = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            count++;
            for (int& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) que.push(v);
            }
        }
        return count == numCourses;
    }
};
