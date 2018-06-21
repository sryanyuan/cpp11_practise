#ifndef _INC_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_
#define _INC_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_

#include "_common_all.h"

class PeakIndexInAMountainArray {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(1);
        nums.push_back(0);
        auto ret = peakIndexInMountainArray(nums);
    }

    static int peakIndexInMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return -1;
        }
        int maxv = -1;
        int pre = A[0];
        for (int i = 1; i < A.size(); i++) {
            int v = A[i];
            if (v == pre) {
                return -1;
            } else if (v - pre > 0) {
                if (maxv != -1) {
                    return -1;
                }
            } else {
                if (maxv == -1) {
                    maxv = i - 1;
                }
            }
            pre = v;
        }
        return maxv;
    }
};

#endif
