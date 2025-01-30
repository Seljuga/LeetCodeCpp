class Solution {
private:
    bool isBipartite = true;
    void dfs(int node, int currColour, vector<vector<int>>& adj, vector<int>& colour, vector<int>& connectedNodes) {
        colour[node] = currColour;
        connectedNodes.push_back(node);
        for (auto it : adj[node]) {
            if (!colour[it]) dfs(it, 3 - currColour, adj, colour, connectedNodes);
            else if (colour[it] == currColour) isBipartite = false;
        }
    }
    int getMaxFromNode(int node, int n, vector<vector<int>>& adj) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(node);
        dist[node] = 1;
        int ans = 1;
        while (!q.empty()) {
            auto cnode = q.front();
            q.pop();
            for (auto it : adj[cnode]) {
                if (dist[it] == -1) {
                    dist[it] = dist[cnode] + 1;
                    q.push(it);
                    ans = max(ans, dist[it]);
                }
            }
        }
        return ans;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> colour(n + 1, 0), connectedNodes;
        int maxGroups = 0;
        for (int i=1; i<=n; i++) {
            if (!colour[i]) {
                connectedNodes = vector<int>();
                isBipartite = true;
                dfs(i, 1, adj, colour, connectedNodes);
                if (!isBipartite) return -1;
                int maxFromComponents = 0;
                for (auto it : connectedNodes) maxFromComponents = max(maxFromComponents, getMaxFromNode(it, n, adj));
                maxGroups += maxFromComponents;
            }
        }
        return maxGroups;
    }
};
