class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int ans = 0;
        for (int i=0; i<size; i++) {
            int nextIndex = (i+1) % size;
            if (nums[i] > nums[nextIndex]) ans++;
        }
        return ans <= 1;
    }
};
