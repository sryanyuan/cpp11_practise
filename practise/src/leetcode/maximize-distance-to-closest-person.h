#ifndef _INC_MAXIMIZE_DISTANCE_TO_CLOSEST_PERSON_
#define _INC_MAXIMIZE_DISTANCE_TO_CLOSEST_PERSON_

#include "_common_all.h"

class MaximizeDistanceToClosestPerson {
public:
    static void test() {
        vector<int> seats;
        seats.push_back(0);
        seats.push_back(1);
        auto ret = maxDistToClosest(seats);
    }

    static int maxDistToClosest(vector<int>& seats) {
        vector<int> pnPos;
        const int maxDist = 40000;
        pnPos.push_back(-1 * maxDist);
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                pnPos.push_back(i);
            }
        }
        pnPos.push_back(maxDist);
        int l = 0;
        int maxp = 0;
        int maxi = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                continue;;
            }
            while (i < pnPos[l] || i > pnPos[l + 1]) {
                l++;
            }
            int distl = maxDist;
            if (pnPos[l] != -1 * maxDist) {
                distl = i - pnPos[l];
            } else {
                distl = maxDist;
            }
            int distr = 0;
            if (pnPos[l + 1] != maxDist) {
                distr = pnPos[l + 1] - i;
            } else {
                distr = maxDist;
            }
            int dist = distl < distr ? distl : distr;
            if (dist > maxp) {
                maxp = dist;
                maxi = i;
            }
        }
        return maxp;
    }
};

#endif
