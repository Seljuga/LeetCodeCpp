class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int size = words.size();
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (i==j) continue;
                if (words[j].find(words[i])!=-1) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
