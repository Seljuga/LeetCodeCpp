class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;
        
        unordered_map<string, int> map;
        int wSize = words.size();
        int length = words[0].length();
        int totalLength = length * wSize;
        int sLength = s.length();
        
        if (sLength < totalLength) return ans;
        for (const string& word : words) map[word]++;
        for (int offset = 0; offset < length; offset++) {
            unordered_map<string, int> t;
            int count = 0, start = offset;
            for (int i = offset; i + length <= sLength; i += length) {
                string st = s.substr(i, length);
                if (map.find(st) != map.end()) {
                    t[st]++; count++;
                    while (t[st] > map[st]) {
                        t[s.substr(start, length)]--;
                        count--;
                        start+=length;
                    }
                    if (count==wSize) ans.push_back(start);
                }
                else {
                    t.clear();
                    count = 0;
                    start = i + length;
                }
            }
        }
        return ans;
    }
};
