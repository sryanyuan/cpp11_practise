#ifndef _INC_NUMBER_OF_ISLANDS_
#define _INC_NUMBER_OF_ISLANDS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:


Input:
11110
11010
11000
00000

Output: 1


Example 2:


Input:
11000
11000
00100
00011

Output: 3

*/

class NumberOfIslands {
public:
	static void test() {
        vector<vector<char>> grid;
		char r1[] = {'1','1','1'};
        vector<char> row(r1, r1 + sizeof(r1) / sizeof(r1[0]));
        grid.push_back(std::move(row));
        char r2[] = {'0','1','0'};
        row.assign(r2, r2 + sizeof(r2) / sizeof(r2[0]));
        grid.push_back(std::move(row));
        char r3[] = {'1','1','1'};
        row.assign(r3, r3 + sizeof(r3) / sizeof(r3[0]));
        grid.push_back(std::move(row));
        auto res = numIslands(grid);
	}

	static int numIslands(vector<vector<char>>& grid) {
		int cnt = 0;
        int rc = grid.size();
        if (0 == rc) {
            return 0;
        }
        int cc = grid[0].size();
        if (0 == cc) {
            return 0;
        }
        for (int i = 0; i < rc; i++) {
            for (int j = 0; j < cc; j++) {
                walk(grid, i, j, cnt);
            }
        }
        return cnt;
	}

    static void walk(vector<vector<char>>& grid, int i, int j, int &cnt) {
        int rc = grid.size();
        int cc = grid[0].size();
        static int offsets[] = {-1, 0, 1, 0, 0, -1, 0, 1};
        if ('1' != grid[i][j]) {
            return;
        }
        bool add = true;
        for (int k = 0; k < sizeof(offsets) / sizeof(offsets[0]); k += 2) {
            int ni = i + offsets[k];
            int nj = j + offsets[k + 1];
            if (ni < 0 || nj < 0 || ni >= rc || nj >= cc) {
                continue;
            }
            if (grid[ni][nj] == '#') {
                add = false;
                break;
            }
        }
        if (add) {
            cnt++;
        }
        grid[i][j] = '#';
        for (int k = 0; k < sizeof(offsets) / sizeof(offsets[0]); k += 2) {
            int ni = i + offsets[k];
            int nj = j + offsets[k + 1];
            if (ni < 0 || nj < 0 || ni >= rc || nj >= cc) {
                continue;
            }
            walk(grid, ni, nj, cnt);
        }
    }
};

#endif
