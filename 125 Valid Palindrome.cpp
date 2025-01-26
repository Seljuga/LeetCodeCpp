class Solution {
public:
    bool isPalindrome(string s) {
        for (auto& letter : s) letter=tolower(letter);
        int element=0, size = s.size()-1;
        auto valid=[](char c) {
            return (c>=65 and c<=90) or (c>=97 and c<=122) or (c-'0'>=0 and c-'0'<=9);
        };
        while (element < size) {
            while (element<size and !valid(s[element])) element++;
            while (element<size and !valid(s[size])) size--;
            if(s[element]!=s[size]) return false;
            element++, size--;
        }
        return true;
    }
};
