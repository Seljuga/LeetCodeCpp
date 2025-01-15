class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(), prefix = 1;
        vector<int> ans(size, 1);
        for (int i=0; i<size; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i=size-1; i>=0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
    }
};
