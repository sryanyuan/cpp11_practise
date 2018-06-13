#ifndef _INC_SET_MISMATCH_
#define _INC_SET_MISMATCH_

#include "_common_all.h"

class SetMismatch {
public:
	static void test() {
		vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(2);
		nums.push_back(3);
		auto ret = main(nums);
	}

	static vector<int> main(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<int> ret(2);
		int offset = 0;

		for (int i = 0; i < nums.size(); i++) {
			int want = i + 1;
			if (nums[i] != want) {
				ret[1] = want;
				// Find duplicated numbers
				for (int j = i + 1; j < nums.size() - 2; j++) {
					if (nums[j] == nums[j + 1]) {
						ret[0] = nums[0];
						return ret;
					}
				}
			}
		}
		return ret;
	}
};

#endif
