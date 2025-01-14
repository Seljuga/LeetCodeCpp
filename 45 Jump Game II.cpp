class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size(), maxDistance = 0;
        int currentMax = 0, total_jumps = 0;
        if (size == 1) return 0;
        if (nums[0] == 0) return false;
        for (int i=0; i<size-1; i++) {
            maxDistance = max(maxDistance, i+nums[i]);
            if (i == currentMax) {
                currentMax = maxDistance;
                total_jumps++;
            }
        }
        return total_jumps;
    }
};
