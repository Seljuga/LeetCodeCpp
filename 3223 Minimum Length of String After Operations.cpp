class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> map;
        int size = s.size(), length = 0;
        for (int i=0; i<size; i++) map[s[i]]++;
        for (auto it : map) {
            if (it.second%2 == 0) length += 2;
            else length++;
        }
        return length;
    }
};
