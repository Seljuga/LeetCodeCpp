class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int size = nums.size();
        vector<pair<int, int>> pairs(size);
        for (int i=0; i<size; i++) pairs[i] = {nums[i], i};
        
        sort(pairs.begin(), pairs.end());
        vector<int> ans (size, 0);
        int count = 0;

        while (count < size) {
            int j = count + 1;
            while (j<size && pairs[j].first - pairs[j - 1].first <= limit) j++;
            vector<int> indices;
            for (int k=count; k<j; k++) indices.push_back(pairs[k].second);
            sort(indices.begin(), indices.end());
            int idx = 0;
            for (int k=count; k<j; k++) {
                ans[indices[idx]] = pairs[k].first;
                idx++;
            }
            count = j;
        }
        return ans;
    }
};
