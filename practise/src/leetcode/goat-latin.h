#ifndef _INC_GOAT_LATIN_
#define _INC_GOAT_LATIN_

#include "_common_all.h"
#include <sstream>

class GoatLatin {
public:
	static string toGoatLatin(string S) {
		std::istringstream is(S);
		std::ostringstream os;
		string word;
		string taila = "a";
		bool first = true;
		while (is >> word) {
			if (!first) {
				os << " ";
			}
			else {
				first = false;
			}
			char ch = tolower(word[0]);
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				os << word << "ma";
			}
			else {
				os << word.substr(1, word.size() - 1 - 1 + 1) << word[0] << "ma";
			}
			os << taila;
			taila += "a";
		}
		return os.str();
	}
};

#endif
