class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (next_perm(nums)) ans.push_back(nums);
        return ans;
    }

    bool next_perm(vector<int>& nums) {
        int n = nums.size(), idx = n - 1;
        for (; idx; idx--) {
            if (nums[idx] > nums[idx - 1]) break;
        }
        if (idx == 0) return false;
        int swapIdx = idx;
        for (auto i=idx; i<n; i++) {
            if ((nums[i]>nums[idx-1]) && (nums[swapIdx]>nums[i])) swapIdx = i;
        }
        swap(nums[idx-1], nums[swapIdx]);
        reverse(nums.begin() + idx, nums.end());
        return true;
    }
};
