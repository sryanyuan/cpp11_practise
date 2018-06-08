#ifndef _INC_FIND_ALL_NUMBERS_DISAPEARED_IN_AN_ARRAY_
#define _INC_FIND_ALL_NUMBERS_DISAPEARED_IN_AN_ARRAY_

#include <vector>
using std::vector;

class FindAllNumbersDisapearedInAnArray {
public:
    static vector<int> main(vector<int>& nums) {
        vector<int> rets;
        for (auto i : nums) {
            int index = abs(i) - 1;
            if (nums[index] < 0) {
                continue;
            }
            nums[index] = -nums[index];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                rets.push_back(i + 1);
            }
        }
        return rets;
    }
};

#endif
