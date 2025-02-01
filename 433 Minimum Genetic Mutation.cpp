class Solution {
    unordered_set<string> visited, edges;
private:
    int diffChars(const string& s1, const string& s2) {
        int size = s1.size();
        if (size != s2.size()) return -1;
        int ans = 0;
        for (int i=0; i<size; i++) {
            if (s1[i] != s2[i]) ans++;
        }
        return ans;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        edges = unordered_set<string> (bank.begin(), bank.end());
        if (!edges.contains(endGene)) return -1;

        q.push(startGene);
        int ans = 0;
        while(!q.empty()) {
            if (edges.empty()) break;
            int levelSize = q.size();
            ans++;
            while(levelSize--) {
                const string cur = q.front();
                q.pop();
                for (const string& s : edges) {
                    if (diffChars(cur, s) == 1 && !visited.contains(s)) {
                        if (s == endGene) return ans;
                        visited.insert(s);
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};
