#ifndef _INC_CONTAINER_WITH_MOST_WATER_
#define _INC_CONTAINER_WITH_MOST_WATER_

#include "_common_all.h"

class ContainerWithMostWater {
public:
    static int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int marea = 0;

        while (l < r) {
            int area = (r - l) * (height[l] < height[r] ? height[l] : height[r]);
            if (area > marea) {
                marea = area;
            }
            bool ml = false, mr = false;
            if (height[l] == height[r]) {
                ml = true; mr = true;
            } else if (height[l] < height[r]) {
                ml = true;
            } else {
                mr = true;
            }
            if (ml) {
                int pl = height[l];
                for (l; l < r; l++) {
                    if (height[l] > pl) {
                        break;
                    }
                }
            }
            if (mr) {
                int pr = height[r];
                for (r; r > l; r--) {
                    if (height[r] > pr) {
                        break;
                    }
                }
            }
        }
        return marea;
    }
};

#endif
