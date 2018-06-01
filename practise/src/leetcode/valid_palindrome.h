#ifndef _INC_VALID_PALINDROME_
#define _INC_VALID_PALINDROME_

#include <string>
using std::string;

class ValidPalindrome {
public:
	static void test() {
		auto ret = main("A man, a plan, a canal: Panama");
		ret = main("race a car");
		ret = main("aa");
	}

	static bool main(string s) {
		if (s.size() <= 1) {
			return true;
		}
		int l = 0;
		int r = s.size() - 1;
		bool ok = true;

		while (l < r) {
			if (!isAlphanumeric(s[l])) {
				l++;
				continue;
			}
			if (!isAlphanumeric(s[r])) {
				r--;
				continue;
			}
			if (tolower(s[l]) != tolower(s[r])) {
				return false;
			}
			l++; r--;
		}

		return true;
	}

	static bool isAlphanumeric(char s) {
		if (s >= 'a' && s <= 'z') {
			return true;
		}
		if (s >= 'A' && s <= 'Z') {
			return true;
		}
		if (s >= '0' && s <= '9') {
			return true;
		}
		return false;
	}
};

#endif
