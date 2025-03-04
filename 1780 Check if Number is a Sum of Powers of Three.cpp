class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n%3 > 1) return 0;
        unordered_set<int> set;
        
        if (n%3 == 1) {
            set.insert(0);
            n--;
        }
        while(n > 0) {
            float cubeRoot = (log(n)/log(3));
            if (set.find(cubeRoot) != set.end()) return 0;
            set.insert(cubeRoot);
            n -= pow(3, static_cast<int>(cubeRoot));
        }
        return 1;
    }
};
