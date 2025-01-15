class Solution {
public:
    int candy(vector<int>& ratings) {
        const int size = ratings.size();
        vector<int> ans(size, 1);

        for (int i=1; i<size; i++) {
            if (ratings[i] > ratings[i-1]) ans[i] = ans[i-1] + 1;
        }
        for (int i=size-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                if (i > 0 && ratings[i-1] < ratings[i]) {
                    ans[i] = max(ans[i+1] + 1, ans[i]);
                    continue;
                }
                ans[i] = ans[i+1] + 1;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};
