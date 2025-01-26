class Solution {
public:
    string reverseWords(string s) {
        string newS = "";
        int size = s.size();
        vector<string> extraS;
        for (int i=0; i<size; i++) {
            if (s[i]!=' ') {
                newS.push_back(s[i]);
                if(i==size-1 && newS!="") extraS.push_back(newS);
            }
            else {
                if (newS!="") extraS.push_back(newS);
                newS = "";
            }
        }
        string ans = "";
        int sizeS = extraS.size();
        for (int i=sizeS-1; i>=0; i--) {
            if (i==0) ans += extraS[i];
            else ans += extraS[i] + " ";
        }
        return ans;
    }
};
