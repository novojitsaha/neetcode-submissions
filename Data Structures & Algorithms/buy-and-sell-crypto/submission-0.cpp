class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;

        int minPrice = prices[0];

        int maxProfit{0};

        for (size_t i{1}; i < prices.size(); ++i)
        {
            if (prices[i - 1] < minPrice)
            {
                minPrice = prices[i - 1];
            }
            int profit = prices[i] - minPrice;

            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
