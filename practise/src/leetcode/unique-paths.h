#ifndef _INC_UNIQUE_PATHS_
#define _INC_UNIQUE_PATHS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:


Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right


Example 2:


Input: m = 7, n = 3
Output: 28
*/

class UniquePaths {
public:
	static void test() {
		auto ret = uniquePaths(23, 12);
	}

	static int uniquePaths(int m, int n) {
        // dynamic programming
		int *cost = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            cost[i] = 0;
        }
        cost[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int upv = 0, leftv = 0;
                if (i - 1 >= 0) {
                    upv = cost[(i - 1) * m + j];
                }
                if (j - 1 >= 0) {
                    leftv = cost[i * m + j - 1];
                }
                cost[i * m + j] = upv + leftv;
            }
        }
        int res = cost[m * n - 1];
        delete[] cost;
        return res;
	}

    // Time exceeded ...
    static void dfs(int m, int n, int cm, int cn, int &sum) {
        if (cm == m - 1 && cn == n - 1) {
            sum++;
            return;
        }
        if (cm < m - 1) {
            dfs(m, n, cm + 1, cn, sum);
        }
        if (cn < n - 1) {
            dfs(m, n, cm, cn + 1, sum);
        }
    }
};

#endif
