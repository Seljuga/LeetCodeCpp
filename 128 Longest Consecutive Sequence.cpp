class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map(nums.begin(), nums.end());
        int ans = 0;
        for (int num : map) {
            if (map.find(num-1) == map.end()) {
                int longest = 1;
                while (map.find(num + longest) != map.end()) longest++;
                ans = max(ans, longest);
            }
        }
        return ans;
    }
};
