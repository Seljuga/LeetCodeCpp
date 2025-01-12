class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2) return 0;

        int sell = n-1, max_profit = 0;
        for (int i=n-2; i>=0; i--) {
            if(prices[i] < prices[sell]) max_profit = max(max_profit, prices[sell] - prices[i]);
            else if(prices[i] > prices[sell]) sell = i;
        }
        return max_profit;
    }
};
