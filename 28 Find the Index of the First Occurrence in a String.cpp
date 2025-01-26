class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()>haystack.size()) return -1;
        int word_size = haystack.size();
        int substring_size = needle.size();
        for (int i=0; i<=word_size-substring_size; i++) {
            if (haystack.substr(i, substring_size) == needle) return i;
        }
        return -1;
    }
};
