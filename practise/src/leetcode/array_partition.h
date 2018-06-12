#ifndef _INC_ARRAY_PARTITION_
#define _INC_ARRAY_PARTITION_

#include <vector>
using std::vector;
#include <algorithm>

class ArrayPartition {
public:
    static int main(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;

        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

#endif
