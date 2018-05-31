#ifndef _INC_MAXIMUM_SUBARRAY_
#define _INC_MAXIMUM_SUBARRAY_

#include <vector>
using std::vector;

class MaximumSubarray {
public:
    static int main(vector<int>& nums) {
        // Kadane's algorithm
        // https://en.wikipedia.org/wiki/Maximum_subarray_problem
        if (nums.empty()) {
            return 0;
        }

        // Total max sum is the maximum sum of the nums
        int nTotalMaxSum = nums[0];
        // Previous max sum is the maximum sum before the i
        int nPrevMaxSum = nums[0];

        // Start index of the maximum array
        int nStart = 0;
        // End index of the maximum array
        int nEnd = 0;

        for (int i = 1; i < int(nums.size()); i++) {
            // At the beginning of the loop, we already known the maximum sum of index 0 (just the value of nums[0])
            // and previous maximum sum of index 0. In the loop, we should calculate the maximum sum of index i, there are
            // two scenarios:
            if (nPrevMaxSum > 0) {
                // 1: The previous maximum sum before i is positive, we should always add nums[i] to it (MUST add the nums[i]) and get the sum of i as the
                // maximum previous sum of index i.
                nPrevMaxSum += nums[i];
            } else {
                // 2: The previous maximum sum before i is negative, do not add it
                nPrevMaxSum = nums[i];
                nStart = i;
            }
            if (nPrevMaxSum > nTotalMaxSum) {
                nTotalMaxSum = nPrevMaxSum;
                nEnd = i;
            }
        }

        return nTotalMaxSum;
    }
};

#endif
