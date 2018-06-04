#ifndef _INC_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_
#define _INC_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

#include <vector>
using std::vector;

class TwoSumII {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(0);
        nums.push_back(3);
        nums.push_back(4);
        auto ret = main(nums, 0);
    }

    static vector<int> main(vector<int>& numbers, int target) {
        if (2 == numbers.size()) {
            if (numbers[0] + numbers[1] == target) {
                vector<int> rets;
                rets.push_back(1);
                rets.push_back(2);
                return rets;
            }
            return vector<int>();
        }
        // Target is added by a number small than it and a number greater than it
        int tmid = target / 2;

        int li = 0;
        int ri = numbers.size() - 1;
        int mi = 0;

        for (;;) {
            mi = (li + ri) / 2;
            if (numbers[mi] < tmid && numbers[mi + 1] > tmid) {
                break;
            }
            if (numbers[mi] == tmid) {
                break;
            }
            if (numbers[mi] < tmid) {
                li = mi;
            } else {
                ri = mi;
            }
        }
        // Move the middle index if previous item has the same value
        for (int i = mi - 1; i >= 0; i--) {
            if (numbers[i] == numbers[mi]) {
                mi = i;
            }
        }

        // Search
        li = 0; ri = 1;
        vector<int> rets;
        rets.resize(2);

        for (;;) {
            if (li + mi < 0 || ri + mi >= numbers.size()) {
                return vector<int>();
            }

            int addRet = numbers[li + mi] + numbers[ri + mi];
            if (addRet == target) {
                rets[0] = li + mi + 1;
                rets[1] = ri + mi + 1;
                return rets;
            }
            if (addRet < target) {
                ++ri;
            } else {
                --li;
            }
        }
    }
};

#endif
