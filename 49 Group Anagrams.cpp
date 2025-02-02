class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string temp(26, 0);
            for (int i=0; i<s.size(); i++) temp[s[i]-'a']++;
            mp[temp].push_back(s);
        }
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};
