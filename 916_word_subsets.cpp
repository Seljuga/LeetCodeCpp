class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> vec(26, 0);
        vector<string> ans;
        for (string st : words2) {
            vector<int> tmp2(26, 0);
            for (auto it : st) tmp2[it - 'a']++;
            for (int i=0; i<26; i++) vec[i] = max(vec[i], tmp2[i]);
        }
        for (auto str : words1) {
            vector<int> tmp1(26,0);
            for (auto it : str) tmp1[it-'a']++;
            int flag = 1;
            for (int i=0; i<26; i++) {
                if(tmp1[i] < vec[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.push_back(str);
        }
        return ans;
    }
};
