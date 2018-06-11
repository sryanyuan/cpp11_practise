#ifndef _INC_HEATERS_
#define _INC_HEATERS_

#include <vector>
using std::vector;
#include <algorithm>

class Heaters {
public:
    static void test() {
        vector<int> houses;
        houses.push_back(1);
        houses.push_back(2);
        houses.push_back(3);
        houses.push_back(4);
        vector<int> heaters;
        heaters.push_back(1);
        heaters.push_back(4);
        auto ret = bs(houses, heaters);
    }

    // Using binary search
    static int bs(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int radius = 0;

        for (int i = 0; i < houses.size(); i++) {
            int curhouse = houses[i];
            int currad = 0;
            if (curhouse <= heaters[0]) {
                currad = abs(heaters[0] - curhouse);
            } else if (curhouse >= heaters[heaters.size() - 1]) {
                currad = abs(heaters[heaters.size() - 1] - curhouse);
            } else {
                int l = 0;
                int r = heaters.size() - 1;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (heaters[mid] == curhouse) {
                        break;
                    }
                    if (heaters[mid] > curhouse) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                if (l >= r) {
                    int lof = abs(heaters[l - 1] - curhouse);
                    int rof = abs(heaters[l] - curhouse);
                    if (lof < rof) {
                        currad = lof;
                    } else {
                        currad = rof;
                    }
                }
            }

            if (currad > radius) {
                radius = currad;
            }
        }
        return radius;
    }

    static int main(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        int radius = 0;

        for (int i = 0; i < houses.size(); i++) {
            int offset = abs(heaters[0] - houses[i]);
            for (int j = 1; j < heaters.size(); j++) {
                int coffset = abs(heaters[j] - houses[i]);
                if (coffset <= offset) {
                    offset = coffset;
                } else {
                    break;
                }
            }
            if (offset > radius) {
                radius = offset;
            }
        }
        return radius;
    }
};

#endif
