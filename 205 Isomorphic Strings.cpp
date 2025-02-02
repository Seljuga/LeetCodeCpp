class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vec(127, -1);
        int size = s.size();
        for (int i=0; i<size; i++) {
            if (vec[s[i]] == -1 || vec[s[i]] == t[i]) vec[s[i]] = t[i];
            else return false;
        }
        
        fill(vec.begin(), vec.end(), -1);

        for(int i=0; i<size; i++) {
            if (vec[t[i]] == -1 || vec[t[i]] == s[i]) vec[t[i]] = s[i];
            else return false;
        }
        return true;
    }
};
