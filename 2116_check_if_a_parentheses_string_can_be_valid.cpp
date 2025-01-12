class Solution {
public:
    bool canBeValid(string s, string locked) {
        int size = s.length();
        if (size%2!=0) return false;
        int open = 0, close = 0;
        for (int i=0; i<size; i++) {
            if (s[i]=='(' || locked[i]=='0') open++;
            else open--;
            if (open<0) return false;
        }
        for (int i=size-1; i>=0; i--) {
            if (s[i]==')' || locked[i]=='0') close++;
            else close--;
            if(close<0) return false;
        }
        return true;
    }
};
