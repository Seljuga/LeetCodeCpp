class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int size=words.size(), ans = 0;
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size; j++) {
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) ans++;
            }
        }
        return ans;
    }
};
