class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        int ans = 0, len = nums.size();
        if (len < 2) return ans;
        
        for (int i=0; i<len; i++) pq.push(nums[i]);

        while(!pq.empty()) {
            long first = pq.top();
            pq.pop();
            long second = pq.top();
            pq.pop();
            if (first < k || second < k) {
                pq.push(min(first, second)*2 + max(first, second));
                ans++;
            }
            else break;
        }
        return ans;
    }
};
