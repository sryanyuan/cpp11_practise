#ifndef _INC_CONTAIN_DUPLICATE_
#define _INC_CONTAIN_DUPLICATE_

#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class ContainDuplicate {
public:
    static bool main(vector<int>& nums) {
        unordered_map<int, int> cnts;

        for (int i = 0; i < nums.size(); i++) {
            auto fnd = cnts.find(nums[i]);
            if (fnd != cnts.end()) {
                return true;
            }
            cnts.insert(std::make_pair(nums[i], 1));
        }

        return false;
    }
};

#endif
