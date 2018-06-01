#ifndef _INC_SINGLE_NUMBER_
#define _INC_SINGLE_NUMBER_

#include <vector>
using std::vector;

class SingleNumber {
public:
	static int main(vector<int>& nums) {
		int cnts[10] = {0};
		for (auto num : nums) {
			cnts[num]++;
		}

		for (int i = 0; i < 10; i++) {
			if (cnts[i] == 1) {
				return i;
			}
		}

		return 0;
	}
};

#endif
