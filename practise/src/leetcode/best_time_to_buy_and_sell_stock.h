#ifndef _INC_BEST_TIME_TO_BUY_AND_SELL_STOCK_
#define _INC_BEST_TIME_TO_BUY_AND_SELL_STOCK_

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <vector>
using std::vector;

class BestTimeToBuyAndSellStock {
public:
    static void test() {
        vector<int> nums;
        int vals[] = {7, 1, 5, 3, 6, 4};
        for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); i++) {
            nums.push_back(vals[i]);
        }
        auto ret = main(nums);
    }

    static int main(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        // Calculate the profit each day
        vector<int> profits;
        profits.resize(prices.size() - 1);
        for (int i = 1; i < prices.size(); i++) {
            profits[i - 1] = prices[i] - prices[i - 1];
        }
        // Get the maximum subarray
        int maxProfit = profits[0];
        int prevMaxProfix = profits[0];

        for (int i = 1; i < profits.size(); i++) {
            if (prevMaxProfix < 0) {
                prevMaxProfix = profits[i];
            } else {
                prevMaxProfix += profits[i];
            }
            if (prevMaxProfix > maxProfit) {
                maxProfit = prevMaxProfix;
            }
        }

        if (maxProfit < 0) {
            return 0;
        }
        return maxProfit;
    }

    static int badSolution(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > maxProfit) {
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        if (maxProfit < 0) {
            return 0;
        }
        return maxProfit;
    }
};

#endif
