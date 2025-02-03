class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int size = nums.size();
        int increasing = 1, decreasing = 1, ans = 1;
        for (int i=1; i<size; i++) {
            if (nums[i]<nums[i-1]) {
                increasing = 1;
                decreasing++;
            }
            else if (nums[i]>nums[i-1]) {
                increasing++;
                decreasing = 1;
            }
            else increasing = decreasing = 1;
            ans = max(ans, max(increasing, decreasing));
        }
        return ans;
    }
};
