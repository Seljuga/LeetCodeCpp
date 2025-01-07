class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        if (size < 2) return size;
        int k=2;
        for (int i=2; i<size; i++) {
            if(nums[i] != nums[k-2]) nums[k++] = nums[i];
        }
        return k;
    }
};
