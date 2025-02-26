class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxI = 0, minI = 0, left = 0, size = nums.size(), cnt = 0;
        for (int right = 0; right < size; right++) {
            cnt += nums[right];
            while (cnt < 0) cnt -= nums[left++];
            maxI = max(maxI, cnt);
        }
        left = cnt = 0;
        for (int right = 0; right < size; right++) {
            cnt -= nums[right];
            while (cnt < 0) cnt += nums[left++];
            minI = max(minI, cnt);
        }
        return max(minI, maxI);
    }
};
