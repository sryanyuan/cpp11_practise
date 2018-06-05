#ifndef _INC_CONTAIN_DUPLICATE_II_
#define _INC_CONTAIN_DUPLICATE_II_

#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;

class ContainDuplicateII {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(3);
        auto ret = main(nums, 3);
    }

    static bool main(vector<int>& nums, int k) {
        unordered_map<int, int> appearIndex;

        for (int i = 0; i < nums.size(); i++) {
            auto fnd = appearIndex.find(nums[i]);
            if (fnd == appearIndex.end()) {
                appearIndex.insert(std::make_pair(nums[i], i));
            } else {
                int nPrevIndex = fnd->second;
                if (i - nPrevIndex <= k) {
                    return true;
                }
                fnd->second = i;
            }
        }

        return false;
    }
};

#endif
