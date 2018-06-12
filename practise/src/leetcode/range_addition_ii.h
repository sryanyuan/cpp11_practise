#ifndef _INC_RANGE_ADDITION_II_
#define _INC_RANGE_ADDITION_II_

class RangeAdditionII {
public:
	static int main(int m, int n, vector<vector<int>>& ops) {
		int ml = m;
		int mr = n;
		for (auto &row : ops) {
			if (row[0] < ml) {
				ml = row[0];
			}
			if (row[1] < mr) {
				mr = row[1];
			}
		}
		return ml * mr;
	}
};

#endif
