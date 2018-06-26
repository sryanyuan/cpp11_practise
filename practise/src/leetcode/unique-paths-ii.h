#ifndef _INC_UNIQUE_PATHS_II_
#define _INC_UNIQUE_PATHS_II_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:


Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*/

class UniquePathsIi {
public:
	static void test() {
		
	}

	static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if (0 == n) {return 0;}
        int m = obstacleGrid[0].size();
        if (0 == m) {return 0;}
		int *cost = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            cost[i] = 0;
        }
        cost[0] = 1;
        if (obstacleGrid[0][0] == 1) {
            cost[0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (0 == i && 0 == j) {
                    continue;
                }
                int upv = 0, leftv = 0;
                if (i - 1 >= 0) {
                    upv = cost[(i - 1) * m + j];
                    if (1 == obstacleGrid[i][j]) {upv = 0;}
                }
                if (j - 1 >= 0) {
                    leftv = cost[i * m + j - 1];
                    if (1 == obstacleGrid[i][j]) {leftv = 0;}
                }
                cost[i * m + j] = upv + leftv;
            }
        }
        int res = cost[m * n - 1];
        delete[] cost;
        return res;
	}
};

#endif
