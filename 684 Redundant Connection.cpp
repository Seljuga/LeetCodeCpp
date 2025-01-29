class Solution {
private:
    bool checkCycle(vector<vector<int>>& graph, vector<bool>& visit, int parent, int s) {
        visit[s] = true;
        for (auto neighbour : graph[s]) {
            if (visit[neighbour] == false) {
                if (checkCycle(graph, visit, s, neighbour)) return true;
            }
            else if (neighbour != parent) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<vector<int>> graph(size + 1);
        for (int i=0; i<size; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            vector<bool> visit(size, false);
            if (checkCycle(graph, visit, edges[i][0], edges[i][1])) return edges[i];
        }
        vector<int> demo;
        return demo;
    }
};
