#ifndef _INC_FIRST_UNIQUE_CHARACTER_IN_A_STRING_
#define _INC_FIRST_UNIQUE_CHARACTER_IN_A_STRING_

#include <string>
using std::string;
#include <algorithm>

class FirstUniqueCharacterInAString {
public:
    static void test() {
		auto ret = main("loveleetcode");
	}

	static int main(string s) {
		if (s.empty()) {
            return -1;
        }
        if (s.size() == 1) {
            return 0;
        }

		int cnts[26] = { 0 };
		char chs[26] = { 0 };
		int fss[26] = { 0 };
		int chi = 0;

		int index = 0;
		for (auto c : s) {
			int i = c - 'a';
			if (cnts[i] == 0) {
				// First time appear
				chs[chi++] = c;
				fss[i] = index;
			}
			cnts[i]++;
			index++;
		}

		for (int i = 0; i < chi; i++) {
			if (cnts[chs[i] - 'a'] == 1) {
				return fss[chs[i] - 'a'];
			}
		}
		return -1;
    }
};

#endif
