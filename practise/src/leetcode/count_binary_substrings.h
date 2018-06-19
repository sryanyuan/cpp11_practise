#ifndef _INC_COUNT_BINARY_SUBSTRINGS_
#define _INC_COUNT_BINARY_SUBSTRINGS_

#include "_common_all.h"

class CountBinarySubstrings {
public:
	static void test() {
		auto ret = main("00110");
	}

	static int main(string s) {
		if (s.empty()) {
			return 0;
		}
		vector<int> cnts;
		cnts.reserve(s.size());
		cnts.push_back(1);
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) {
				cnts[cnts.size() - 1]++;
			}
			else {
				cnts.push_back(1);
			}
		}
		if (cnts.size() <= 1) { return 0; }
		int cnt = 0;
		for (int i = 1; i < cnts.size(); i++) {
			if (cnts[i - 1] < cnts[i]) {
				cnt += cnts[i - 1];
			}
			else {
				cnt += cnts[i];
			}
		}
		return cnt;
	}

	static int slow(string s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (bsub(s, i)) {
				cnt++;
			}
		}
		return cnt;
	}

	static bool bsub(string &s, int si) {
		int zcnt = 0;
		int ocnt = 0;
		char pc = 0;
		bool swi = false;
		for (int i = si; i < s.size(); i++) {
			if (pc == 0) {
				pc = s[i];
				if (pc == '0') {
					++zcnt;
				}
				else {
					++ocnt;
				}
				continue;
			}
			if (swi && s[i] == pc) {
				return false;
			}
			if (s[i] == '0') {
				++zcnt;
			}
			else if (s[i] == '1') {
				++ocnt;
			}
			if (s[i] != pc) {
				swi = true;
				if (zcnt == ocnt) {
					return true;
				}
			}
		}
		return false;
	}
};

#endif
