class Solution {
private:
    void backtrack(unordered_map<char, int>& count, int& ans, int length) {
        if (length == 0) return;
        for (auto& [ch, freq] : count) {
            if (freq > 0) {
                ans++;
                count[ch]--;
                backtrack(count, ans, length - 1);
                count[ch]++;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (const char c : tiles) count[c]++;
        int ans = 0;
        backtrack(count, ans, tiles.size());
        return ans;
    }
};
