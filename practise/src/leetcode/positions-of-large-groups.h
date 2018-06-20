#ifndef _INC_POSITIONS_OF_LARGE_GROUPS_
#define _INC_POSITIONS_OF_LARGE_GROUPS_

#include "_common_all.h"

class PositionsOfLargeGroups {
public:
	static vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> rets;
		char prec = S[0];
		int cnt = 1;
		int si = 0;

		for (int i = 1; i < S.size(); i++) {
			if (prec == S[i]) {
				++cnt;
			}
			if (prec != S[i] || i == S.size() - 1) {
				if (cnt >= 3) {
					int index = prec - 'a';
					vector<int> ret;
					ret.push_back(si);
					ret.push_back(si + cnt - 1);
					rets.push_back(std::move(ret));
				}
				prec = S[i];
				cnt = 1;
				si = i;
			}
		}

		return rets;
	}
};

#endif
