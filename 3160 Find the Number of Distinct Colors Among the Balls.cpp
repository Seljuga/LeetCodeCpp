class Solution {
public:
    vector<int> ans;
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor;
        unordered_map<int, int> colorCnt;

        for (auto& it : queries) {
            int ball = it[0], newCol = it[1];
            if (ballToColor.find(ball) != ballToColor.end()) {
                int oldCol = ballToColor[ball];
                colorCnt[oldCol]--;
                if (colorCnt[oldCol] == 0) colorCnt.erase(oldCol);
            }
            ballToColor[ball] = newCol;
            colorCnt[newCol]++;
            ans.push_back(colorCnt.size());
        }
        return ans;
    }
};
