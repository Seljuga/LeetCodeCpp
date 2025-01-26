class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128, -1);
        int size = s.size(), left = 0;
        int ans = 0;
        for (int i=0; i<size; i++) {
            auto element = vec[s[i]];
            if (element >= left) left = element + 1;
            vec[s[i]] = i;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
