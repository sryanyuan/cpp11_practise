#ifndef _INC_MAGIC_SQUARES_IN_GRID_
#define _INC_MAGIC_SQUARES_IN_GRID_

#include "_common_all.h"

class MagicSquaresInGrid {
public:
    static void test() {
        vector<vector<int>> grid;
        vector<int> row;
        int r1[] = {9,9,5,1,9,5,5,7,2,5};
        for (int i = 0; i < 10; i++) {
            row.push_back(r1[i]);
        }
        grid.push_back(std::move(row));
        int r2[] = {9,1,8,3,4,6,7,2,8,9};
        for (int i = 0; i < 10; i++) {
            row.push_back(r2[i]);
        }
        grid.push_back(std::move(row));
        int r3[] = {4,1,1,5,9,1,5,9,6,4};
        for (int i = 0; i < 10; i++) {
            row.push_back(r3[i]);
        }
        grid.push_back(std::move(row));
        int r4[] = {5,5,6,7,2,8,3,4,0,6};
        for (int i = 0; i < 10; i++) {
            row.push_back(r4[i]);
        }
        grid.push_back(std::move(row));
        int r5[] = {1,9,1,8,3,1,4,2,9,4};
        for (int i = 0; i < 10; i++) {
            row.push_back(r5[i]);
        }
        grid.push_back(std::move(row));
        int r6[] = {2,8,6,4,2,7,3,2,7,6};
        for (int i = 0; i < 10; i++) {
            row.push_back(r6[i]);
        }
        grid.push_back(std::move(row));
        int r7[] = {9,2,5,0,7,8,2,9,5,1};
        for (int i = 0; i < 10; i++) {
            row.push_back(r7[i]);
        }
        grid.push_back(std::move(row));
        int r8[] = {2,1,4,4,7,6,2,4,3,8};
        for (int i = 0; i < 10; i++) {
            row.push_back(r8[i]);
        }
        grid.push_back(std::move(row));
        int r9[] = {1,2,5,3,0,5,10,8,5,2};
        for (int i = 0; i < 10; i++) {
            row.push_back(r9[i]);
        }
        grid.push_back(std::move(row));
        int r10[] = {6,9,6,8,8,4,3,6,0,9};
        for (int i = 0; i < 10; i++) {
            row.push_back(r10[i]);
        }
        grid.push_back(std::move(row));
        auto ret = numMagicSquaresInside(grid);
    }

    static int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int r = 2; r < grid.size(); r++) {
            cnt += checkMS(grid[r - 2], grid[r - 1], grid[r]);
        }
        return cnt;
    }

    static int checkMS(vector<int> &r1, vector<int> &r2, vector<int> &r3) {
        int cnt = 0;
        for (int i = 2; i < r1.size(); i++) {
            bool ok = true;
            int cnts[9] = {0};
            for (int j = i; j >= i - 2; j--) {
                int v = r1[j];
                if (v < 1 || v > 9) {
                    ok = false;
                    break;
                }
                cnts[v - 1]++;
                if (cnts[v - 1] > 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = i; j >= i - 2; j--) {
                int v = r2[j];
                if (v < 1 || v > 9) {
                    ok = false;
                    break;
                }
                cnts[v - 1]++;
                if (cnts[v - 1] > 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            for (int j = i; j >= i - 2; j--) {
                int v = r3[j];
                if (v < 1 || v > 9) {
                    ok = false;
                    break;
                }
                cnts[v - 1]++;
                if (cnts[v - 1] > 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            int sum = r1[i - 2] + r1[i - 1] + r1[i + 0];
            if (sum == r2[i - 2] + r2[i - 1] + r2[i + 0] &&
                sum == r3[i - 2] + r3[i - 1] + r3[i + 0] &&
                sum == r1[i - 2] + r2[i - 2] + r3[i - 2] &&
                sum == r1[i - 1] + r2[i - 1] + r3[i - 1] &&
                sum == r1[i + 0] + r2[i + 0] + r3[i + 0] &&
                sum == r1[i - 2] + r2[i - 1] + r3[i + 0] &&
                sum == r1[i + 0] + r2[i - 1] + r3[i - 2]) {
                    ++cnt;
            }
        }
        return cnt;
    }
};

#endif
