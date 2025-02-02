class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for (char it : magazine) map[it]++;
        for (int i=0; i<ransomNote.length(); i++) {
            if (map.find(ransomNote[i]) != map.end()) map[ransomNote[i]]--;
            else return false;
        }
        for (auto& it : map) {
            if (it.second<0) return false;
        }
        return true;
    }
};
