#ifndef _INC_LARGEST_NUMBER_AT_LEAST_TWICE_OF_OTHERS_
#define _INC_LARGEST_NUMBER_AT_LEAST_TWICE_OF_OTHERS_

#include "_common_all.h"

class LargestNumberAtLeastTwiceOfOthers {
public:
    static int main(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int li = 0;
        vector<int> nc = nums;
        std::sort(nc.begin(), nc.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nc[nc.size() - 1]) {
                li = i;
                break;
            }
        }
        if (nc[nc.size() - 1] >= nc[nc.size() - 2] * 2) {
            return li;
        }
        return -1;
    }
};

#endif
