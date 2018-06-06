#ifndef _INC_RANGE_SUM_QUERY_IMMUTABLE_
#define _INC_RANGE_SUM_QUERY_IMMUTABLE_

#include <vector>
using std::vector;

class RangeSumQueryImmutable {
public:
    static void test() {
        vector<int> nums;
        nums.push_back(-2);
        nums.push_back(0);
        nums.push_back(3);
        nums.push_back(-5);
        nums.push_back(2);
        nums.push_back(-1);
        
        NumArray array(nums);
        auto ret = array.sumRange(0, 2);
        ret = array.sumRange(2, 5);
        ret = array.sumRange(0, 5);
    }

    class NumArray {
    public:
        NumArray(vector<int> nums) {
            nums_ = std::move(nums);
            sum_cache_.resize(nums_.size());

            int sum = 0;
            for (int i = 0; i < nums_.size(); i++) {
                sum += nums_[i];
                sum_cache_[i] = sum;
            }
        }

        int sumRange(int i, int j) {
            if (i == 0) {
                return sum_cache_[j];
            }
            return sum_cache_[j] - sum_cache_[i - 1];
        }

    private:
        vector<int> nums_;
        vector<int> sum_cache_;
    };
};

#endif
