class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, end=0, size = nums.size();
        int sum = 0, ans = 1e9+7;
        while(start <= end && end < size) {
            sum += nums[end++];
            while(sum >= target && start <= end) {
                ans = min(ans, end-start);
                sum -= nums[start++];
            }
        }
        return ans == 1e9+7 ? 0 : ans;
    }
};
