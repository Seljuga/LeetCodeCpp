class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        if(nums[0] == 0) return false;
        int minRequiredJump = 1;
        for (int i=size-2; i>=0; i--) {
            if(nums[i] >= minRequiredJump) minRequiredJump = 1;
            else minRequiredJump++;
        }
        return minRequiredJump == 1 ? true : false;
    }
};
