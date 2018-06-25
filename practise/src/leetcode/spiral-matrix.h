#ifndef _INC_SPIRAL_MATRIX_
#define _INC_SPIRAL_MATRIX_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:


Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]


Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class SpiralMatrix {
public:
	static void test() {
		
	}

	static vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty()) {
            return vector<int>();
        }
        if (matrix.size() == 1) {
            return matrix[0];
        }
        int m = matrix.size();
        int n = matrix[0].size();

		int ci = 0, cj = 0;
        vector<int> res;
        int dir = 0;
        int offset = 0;
        for (int i = 0; i < m * n; i++) {
			res.push_back(matrix[ci][cj]);
			if (dir == 0) {
				cj++;
				if (cj > n - 1 - offset) {
					cj = n - 1 - offset;
					ci++;
					dir++;
				}
			}
			else if (dir == 1) {
				ci++;
				if (ci > m - 1 - offset) {
					ci = m - 1 - offset;
					cj--;
					dir++;
				}
			}
			else if (dir == 2) {
				cj--;
				if (cj < offset) {
					cj = offset;
					ci--;
					dir++;
				}
			}
			else if (dir == 3) {
				ci--;
				if (ci <= offset) {
					offset++;
					ci = offset;
					dir = 0;
					cj++;
				}
			}
        }
		return res;
	}
};

#endif
