class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int size = nums.size();
        string ans = "";
        for (int i=0; i<size; i++) ans += (nums[i][i] == '1') ? '0' : '1';
        return ans;
    }
};
