class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int size = nums.size() - 1;
        for (int i=0; i<size; i++) {
            if ((nums[i] % 2 == 0 && nums[i+1] % 2 == 0) || (nums[i]%2==1 && nums[i+1]%2==1)) return false;
        }
        return true;
    }
};
