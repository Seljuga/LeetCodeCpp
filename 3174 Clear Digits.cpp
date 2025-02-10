class Solution {
public:
    string clearDigits(string s) {
        int count = 0, size = s.length();
        string ans = "";
        for (int i=size-1; i>=0; i--) {
            if (isdigit(s[i])) count++;
            else if (count != 0) count--;
            else ans = s[i] + ans;
        }
        return ans;
    }
};
