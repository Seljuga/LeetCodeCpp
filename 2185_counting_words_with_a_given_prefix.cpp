class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string str : words) {
            if(str.substr(0, pref.length()) == pref) ans++;
        }
        return ans;
    }
};
