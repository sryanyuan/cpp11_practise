#ifndef _INC_LONGEST_CONTINUOUS_INCREASING_SUBSEQUENCE_
#define _INC_LONGEST_CONTINUOUS_INCREASING_SUBSEQUENCE_

#include "_common_all.h"

class LongestContinuousIncreasingSubsequence {
public:
    static int main(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int mcnt = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
            } else {
                if (cnt > mcnt) {
                    mcnt = cnt;
                }
                cnt = 1;
            }
        }

        return cnt > mcnt ? cnt : mcnt;
    }
};

#endif
