#ifndef _INC_SET_MISMATCH_
#define _INC_SET_MISMATCH_

#include "_common_all.h"

class SetMismatch {
public:
	static void test() {
		vector<int> nums;
		nums.push_back(1);
		nums.push_back(1);
		auto ret = main(nums);
	}

	static vector<int> main(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<int> ret(2);

		int pre = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (pre != nums[i] - 1) {
				if (pre == nums[i]) {
					ret[0] = pre;
				}
				else {
					ret[1] = pre + 1;
				}
			}
			pre = nums[i];
			if (0 != ret[0] && 0 != ret[1]) {
				return ret;
			}
		}
		return ret;
	}
};

#endif
