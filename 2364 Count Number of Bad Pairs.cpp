class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long size = nums.size();
        map<int, int> map;
        long long s = (size * (size - 1)) / 2;
        long long c {};
        for (int i=0; i<size; i++) {
            int tmp = nums[i] - i;
            c += map[tmp];
            map[tmp]++;
        }
        return s - c;
    }
};
