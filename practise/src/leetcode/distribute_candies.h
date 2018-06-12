#ifndef _INC_DISTRIBUTE_CANDIES_
#define _INC_DISTRIBUTE_CANDIES_

#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class DistributeCandies {
public:
    static int main(vector<int>& candies) {
        int num = 0;
        unordered_map<int, int> vals;
        for (int i = 0; i < candies.size(); i++) {
            auto fnd = vals.find(candies[i]);
            if (fnd == vals.end()) {
                vals.insert(std::make_pair(candies[i], 1));
                ++num;
                if (num >= candies.size() / 2) {
                    break;
                }
            }
        }
        return num;
    }
};

#endif
