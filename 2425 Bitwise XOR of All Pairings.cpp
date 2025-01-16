class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int a = 0, b = 0;
        for (auto &it : nums1) a^=it;
        for (auto &it : nums2) b^=it;
        if (size1 % 2 == 0 && size2 % 2 == 0) return 0;
        if (size1 % 2 == 0 && size2 % 2 == 1) return a;
        if (size1 % 2 == 1 && size2 % 2 == 0) return b;
        return a^b;
    }
};
