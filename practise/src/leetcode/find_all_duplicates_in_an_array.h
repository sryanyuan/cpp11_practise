#ifndef _INC_FIND_ALL_DUPLICATES_IN_AN_ARRAY_
#define _INC_FIND_ALL_DUPLICATES_IN_AN_ARRAY_

#include <vector>
using std::vector;

class FindAllDuplicatesInAnArray {
public:
    static vector<int> main(vector<int>& nums) {
        vector<int> rets;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                rets.push_back(index + 1);
            } else {
                nums[index] = -nums[index];
            }
        }
        return rets;
    }
};

#endif
