#ifndef _INC_MAX_AREA_OF_ISLAND_
#define _INC_MAX_AREA_OF_ISLAND_

#include "_common_all.h"

class MaxAreaOfIsland {
public:
	static int main(vector<vector<int>>& grid) {
		int my = grid.size();
		if (0 == my) {
			return 0;
		}
		int mx = grid[0].size();
		if (0 == mx) {
			return 0;
		}
		unordered_map<int, int> looked;
		int marea = 0;
		for (int y = 0; y < my; y++) {
			for (int x = 0; x < mx; x++) {
				int area = 0;
				look(grid, x, y, mx, my, looked, area);
				if (area > marea) {
					marea = area;
				}
			}
		}
		return marea;
	}

	static void look(vector<vector<int>>& grid, int x, int y, int mx, int my, unordered_map<int, int> &looked, int &area) {
		static int offsets[] = { -1, 0, 1, 0, 0, -1, 0, 1 };
		if (grid[y][x] == 0) {
			return;
		}
		auto fnd = looked.find((x << 8) | y);
		if (fnd != looked.end()) {
			return;
		}
		looked.insert(std::make_pair((x << 8) | y, 1));
		area += 1;

		for (int i = 0; i < sizeof(offsets) / sizeof(offsets[0]); i += 2) {
			int tx = x + offsets[i];
			int ty = y + offsets[i + 1];
			if (tx < 0 || tx >= mx) {
				continue;
			}
			if (ty < 0 || ty >= my) {
				continue;
			}
			look(grid, tx, ty, mx, my, looked, area);
		}
	}
};

#endif
