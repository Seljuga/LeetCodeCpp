class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector<int> freqTable(256, 0);
        for (int i=0; i<sSize; i++) freqTable[s[i]]++;
        for (int i=0; i<tSize; i++) freqTable[t[i]]--;
        for(auto it : freqTable) if(it!=0) return false;
        return true;
    }
};
