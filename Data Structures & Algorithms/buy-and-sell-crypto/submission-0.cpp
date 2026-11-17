class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 1;
        int minPrice = prices[0];
        int maxprofit = 0;
        
        while (i < prices.size()) {
            if (prices[i] <= minPrice)
                minPrice = prices[i];
            else
                maxprofit = max(maxprofit, prices[i] - minPrice);

            i++;
        }
        
        return maxprofit;
    }
};
