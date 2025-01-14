class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> idx_map;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if(idx_map.find(val) != idx_map.end()) return false;
        nums.push_back(val);
        idx_map[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (idx_map.find(val) == idx_map.end()) return false;
        int last_element = nums.back();
        int idx_to_remove = idx_map[val];

        nums[idx_to_remove] = last_element;
        idx_map[last_element] = idx_to_remove;
        nums.pop_back();
        idx_map.erase(val);

        return true;
    }
    
    int getRandom() {
        int random_idx = rand() % nums.size();
        return nums[random_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
