#ifndef _INC_LONGEST_WORD_IN_DICTIONARY_
#define _INC_LONGEST_WORD_IN_DICTIONARY_

#include "_common_all.h"

class LongestWordInDictionary {
public:
	string main(vector<string>& words) {
		std::sort(words.begin(), words.end(), [](const string& l, const string &r) -> bool{
			return r.size() >= l.size();
		});
		vector<string> results;
		int curlen = 1;
		int curend = 0;
		int curstart = 0;
		for (int wi = 0; wi < words.size(); wi++) {
			string &str = words[wi];
			if (curlen == str.size()) {
				if (1 == curlen) {
					results.push_back(str);
					curend++;
				}
				else {
					// Check prefix
					int i = 0;
					for (i = curstart; i < curend; i++) {
						if (0 == str.find(results[i])) {
							break;
						}
					}
					if (i != curend) {
						results.push_back(str);
						curend++;
					}
				}
			}
			else {
				++curlen;
				if (wi < words.size() - 1) {
					if (curlen != words[wi + 1].size()) {
						break;
					}
				}
			}
		}
	}
};

#endif
