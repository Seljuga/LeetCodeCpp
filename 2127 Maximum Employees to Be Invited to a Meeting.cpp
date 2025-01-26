class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int size = favorite.size();
        vector<vector<int>> reversedGraph(size);
        for (int person = 0; person < size; person++) reversedGraph[favorite[person]].push_back(person);

        auto bfs = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> q;
            q.push({startNode, 0});
            int maxDistance = 0;
            while (!q.empty()) {
                auto [currentNode, currentDistance] = q.front();
                q.pop();
                for (int neighbour : reversedGraph[currentNode]) {
                    if (visitedNodes.count(neighbour)) continue;
                    visitedNodes.insert(neighbour);
                    q.push({neighbour, currentDistance + 1});
                    maxDistance = max(maxDistance, currentDistance + 1);
                }
            }
            return maxDistance;
        };

        int longestCycle = 0, twoCycleInvitations = 0;
        vector<bool> visited(size, false);
        
        for (int person = 0; person < size; person++) {
            if (!visited[person]) {
                unordered_map<int, int> visitedPersons;
                int current = person, distance = 0;
                while (true) {
                    if (visited[current]) break;
                    visited[current] = true;
                    visitedPersons[current] = distance++;
                    int nextPerson = favorite[current];
                    if (visitedPersons.count(nextPerson)) {
                        int cycleLength = distance - visitedPersons[nextPerson];
                        longestCycle = max(longestCycle, cycleLength);
                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {current, nextPerson};
                            int chain1 = bfs(nextPerson, visitedNodes);
                            int chain2 = bfs(current, visitedNodes);
                            twoCycleInvitations += 2 + chain1 + chain2;
                        }
                        break;
                    }
                    current = nextPerson;
                }
            }
        }
        return max(longestCycle, twoCycleInvitations);
    }
};
