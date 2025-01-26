class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m==0 || n==0 || n>m) return "";

        unordered_map<char, int> map;
        for(int i=0; i<n; i++) map[t[i]]++;
        
        vector<int> ans = {INT_MAX, -1};
        unordered_map<char, int> windowMap;
        int left = 0, found = 0, desired = map.size();
        for (int right=0; right<m; right++) {
            windowMap[s[right]]++;
            if (map.find(s[right]) != map.end() && windowMap[s[right]] == map[s[right]]) found++;
            while (found == desired) {
                if((right-left+1) < ans[0]) ans = {(right-left+1), left};
                windowMap[s[left]]--;
                if (map.find(s[left]) != map.end() && windowMap[s[left]] < map[s[left]]) found--;
                left++;
            }
        }
        if (ans[0] == INT_MAX) return "";
        return s.substr(ans[1], ans[0]);
    }
};
