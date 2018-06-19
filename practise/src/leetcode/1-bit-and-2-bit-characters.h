#ifndef _INC_1_BIT_AND_2_BIT_CHARACTERS_
#define _INC_1_BIT_AND_2_BIT_CHARACTERS_

#include "_common_all.h"

class OneBitAndTwoBitCharacters {
public:
	bool main(vector<int>& bits) {
		bool tf = false;
		for (int i = 0; i < bits.size(); i++) {
			int value = bits[i];
			if (value == 0 && !tf) {
				tf = false;
				if (i == bits.size() - 1) {
					return true;
				}
				continue;
			}
			if (value == 1 || tf) {
				if (tf) {
					tf = false;
				}
				else {
					tf = true;
				}
				if (i == bits.size() - 1) {
					return false;
				}
			}
		}
		return false;
	}
};

#endif
