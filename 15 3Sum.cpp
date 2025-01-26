class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<size; i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int j=i+1, k=size-1;
            while (j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum<0) j++;
                else if (sum>0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j<k && nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};
