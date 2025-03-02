class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> mp;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i=0; i < n1; ++i) mp[nums1[i][0]] = nums1[i][1];
        for (int i=0; i < n2; ++i) mp[nums2[i][0]] += nums2[i][1];

        vector<vector<int>> ans;

        for (auto& i : mp) ans.push_back({i.first, i.second});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
