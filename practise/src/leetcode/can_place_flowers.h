#ifndef _INC_CAN_PLACE_FLOWERS_
#define _INC_CAN_PLACE_FLOWERS_

#include <vector>
using std::vector;

class CanPlaceFlowers {
public:
    static void test() {
        vector<int> rets;
        rets.push_back(1);
        rets.push_back(0);
        rets.push_back(0);
        rets.push_back(0);
        rets.push_back(1);
        rets.push_back(0);
        rets.push_back(0);
        auto ret = main(rets, 2);
    }

    static bool main(vector<int>& flowerbed, int n) {
        if (n <= 0) {
            return true;
        }
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n == 1) {
                return true;
            }
            return false;
        }
        int pre = -1;
        for (int i = 0; i < flowerbed.size(); i++) {
            int cur = flowerbed[i];
            int next = -1;
            if (i + 1 < flowerbed.size()) {
                next = flowerbed[i + 1];
            }
            if (cur == 0 && pre <= 0 && next <= 0) {
                cur = 1;
                n--;
            }
            pre = cur;
            if (n <= 0) {
                return true;
            }
        }
        return false;
    }
};

#endif
