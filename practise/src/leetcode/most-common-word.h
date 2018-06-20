#ifndef _INC_MOST_COMMON_WORD_
#define _INC_MOST_COMMON_WORD_

#include "_common_all.h"

class MostCommonWord {
public:
	string main(string paragraph, vector<string>& banned) {
		unordered_map<string, int> wordCnts;
		char wchars[11] = { 0 };
		char ii = 0;
		string cp = paragraph + " ";

		unordered_set<string> bmap;
		for (auto &v : banned) {
			bmap.insert(v);
		}

		for (auto c : cp) {
			if (isalpha(c)) {
				wchars[ii++] = tolower(c);
			}
			else if (c == ' ') {
				wchars[ii] = 0;
				ii = 0;
				string w = wchars;
				if (bmap.count(w) == 0) {
					auto fnd = wordCnts.find(w);
					if (fnd == wordCnts.end()) {
						wordCnts.insert(std::make_pair(std::move(w), 1));
					}
					else {
						fnd->second++;
					}
				}
			}
		}
		vector<string> cmpv;
		int maxv = 0;
		string maxw;
		for (auto &pa : wordCnts) {
			if (0 == maxv || pa.second > maxv) {
				maxv = pa.second;
				maxw = std::move(pa.first);
			}
		}
		return maxw;
	}
};

#endif
