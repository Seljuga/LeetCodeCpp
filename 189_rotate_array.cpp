class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), index = size - (k % size);
        reverse(nums.begin(), nums.end() - (k % size));
        reverse(nums.begin() + index, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
