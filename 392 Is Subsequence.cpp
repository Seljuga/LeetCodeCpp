class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size = s.size();
        if (size > t.size()) return false;
        int nChar = 0;
        for (char e : t) {
            if (nChar == size) return true;
            if (s[nChar] == e) nChar++;
        }
        if (nChar == size) return true;
        return false;
    }
};
