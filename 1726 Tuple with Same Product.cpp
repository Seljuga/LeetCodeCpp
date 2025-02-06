class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> productFreq;
        int ans = 0;
        
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size; j++) {
                productFreq[nums[i] * nums[j]]++;
            }
        }
        for (auto& [product, freq] : productFreq) {
            if (freq >= 2) ans += (freq * (freq - 1) / 2) * 8;
        }
        return ans;
    }
};
