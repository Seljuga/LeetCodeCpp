class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        string ans;
        if (size<=1 || numRows==1) return s;
        for (int i=0; i<numRows; i++) {
            int j=i;
            while (j<size) {
                ans += s[j];
                if (i%(numRows-1) && (j+2+2*(numRows-1-(i+1))) < size) ans += s[j + 2 + 2*(numRows-1-(i+1))];
                j += 2*numRows - 2;
            }
        }
        return ans;
    }
};
