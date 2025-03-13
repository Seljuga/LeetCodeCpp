class Solution {
private:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int n, int m, int k) {
        vector<int> diff(n);
        for(int i=0; i<min(m,k); i++){
            diff[queries[i][0]] += queries[i][2];
            if(queries[i][1] < n-1) diff[queries[i][1]+1]-=queries[i][2];
        }
        int pre = 0;
        for(int i=0; i<n; i++){
            pre += diff[i];
            if(pre<nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int l = 0,r = m;
        while(l <= r){
            int mid=(l + r)/2;
            if(isZeroArray(nums, queries, n, m, mid)) r = mid-1;
            else l = mid+1;
        }
        return l > m ? -1 : l;
    }
};
