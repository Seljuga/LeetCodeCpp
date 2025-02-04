class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int size = nums.size();
        int ans = nums[0], sum = nums[0], right = 1;
        while (right < size) {
            if (nums[right] > nums[right - 1]) sum += nums[right];
            else {
                ans = max(ans, sum);
                sum = nums[right];
            }
            right++;
        }
        return max(ans, sum);
    }
};
