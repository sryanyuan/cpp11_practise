#ifndef _INC_MINIMUM_MOVES_TO_EQUAL_ARRAY_ELEMENTS_
#define _INC_MINIMUM_MOVES_TO_EQUAL_ARRAY_ELEMENTS_

#include <vector>
using std::vector;

class MinimumMovesToEqualArrayElements {
public:
    static int main(vector<int>& nums) {
        // https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
        int sum = 0;
        int minNum = nums[0];
        for (auto i : nums) {
            sum += i;
            if (i < minNum) {
                minNum = i;
            }
        }
        return sum - minNum * nums.size();
    }
};

#endif
