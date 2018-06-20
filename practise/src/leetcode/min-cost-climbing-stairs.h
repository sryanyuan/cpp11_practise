#ifndef _INC_MIN_COST_CLIMBING_STAIRS_
#define _INC_MIN_COST_CLIMBING_STAIRS_

#include "_common_all.h"

class MinCostClimbingStairs {
public:
    static void test() {
        vector<int> cost;
        int costs[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        for (int i = 0; i < sizeof(costs) / sizeof(costs[0]); i++) {
            cost.push_back(costs[i]);
        }
        auto ret = main(cost);
    }

    static int main(vector<int>& cost) {
        int lcost = cost[0], rcost = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int nlcost = lcost + cost[i];
            int nrcost = rcost + cost[i];
            int fcost = nlcost < nrcost ? nlcost : nrcost;
            lcost = rcost; rcost = fcost;
        }
        return lcost < rcost ? lcost : rcost;
    }

    static int verbose(vector<int>& cost) {
        int lcost = cost[0], rcost = cost[1];
        if (cost.size() == 2) {
            return lcost < rcost ? lcost : rcost;
        }
        vector<int> fcosts;
        if (1 + 2 >= cost.size()) {
            fcosts.push_back(cost[1]);
        }
        for (int i = 2; i < cost.size(); i++) {
            int nlcost = lcost + cost[i];
            int nrcost = rcost + cost[i];
            int fcost = nlcost < nrcost ? nlcost : nrcost;
            lcost = rcost; rcost = fcost;
            if (i + 2 >= cost.size()) {
                fcosts.push_back(fcost);
            }
        }
        std::sort(fcosts.begin(), fcosts.end());
        return fcosts[0];
    }
};

#endif
