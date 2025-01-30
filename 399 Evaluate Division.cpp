class Solution {
private:
    double helper(string str, string dest, unordered_map<string, vector<pair<string, double>>>& umap, unordered_map<string, bool>& visit) {
        if (visit[str]) return -1.0;
        visit[str] = true;
        for (auto i : umap[str]) {
            if (i.first == dest) return i.second*1.0;
            double next = helper(i.first, dest, umap, visit);
            if (next != -1) return i.second * next;
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> umap;
        int size = equations.size();
        for (int i=0; i<size; i++) {
            umap[equations[i][0]].push_back({equations[i][1], values[i]});
            umap[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> ans;
        for (auto s : queries) {
            unordered_map<string, bool> visit;
            ans.push_back(helper(s[0], s[1], umap, visit));
        }
        return ans;
    }
};
