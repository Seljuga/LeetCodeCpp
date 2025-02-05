class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> map;
        int size = nums.size(), count=0;
        for (int i=0; i<min(k+1, size); i++) {
            if (map.count(nums[i])) return true;
            map.insert(nums[i]);
            count++;
        }
        for (count; count<size; count++) {
            map.erase(nums[count-k-1]);
            if(map.count(nums[count])) return true;
            map.insert(nums[count]);
        }
        return false;
    }
};
