#ifndef _INC_FIND_THE_DIFFERENCE_
#define _INC_FIND_THE_DIFFERENCE_

#include <string>
using std::string;

class FindTheDifference {
public:
	static char main(string s, string t) {
		int cnts[26] = { 0 };
		int i = 0, j = 0;

		while (i < s.size() || j < t.size()) {
			if (i < s.size()) {
				cnts[s[i] - 'a']++;
			}
			if (j < t.size()) {
				cnts[t[j] - 'a']--;
			}
			i++; j++;
		}

		for (int i = 0; i < 26; i++) {
			if (cnts[i] != 0) {
				return i + 'a';
			}
		}
		return 0;
	}
};

#endif
