#ifndef _INC_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_
#define _INC_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_

#include <vector>
using std::vector;

class BestTimeToBuyAndSellStockII {
public:
	static int main(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}

		vector<int> profits;
		profits.resize(prices.size() - 1);
		for (int i = 1; i < prices.size(); i++) {
			profits[i - 1] = prices[i] - prices[i - 1];
		}

		int maxProfits = 0;
		for (auto profit : profits) {
			if (profit > 0) {
				maxProfits += profit;
			}
		}
		return maxProfits;
	}
};

#endif
