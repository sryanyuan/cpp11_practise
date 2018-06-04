#ifndef _INC_SINGLE_NUMBER_
#define _INC_SINGLE_NUMBER_

#include <vector>
using std::vector;

class SingleNumber {
public:
	static int main(vector<int>& nums) {
		int ret = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			ret ^= nums[i];
		}
		return ret;
	}
};

#endif
