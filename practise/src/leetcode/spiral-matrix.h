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
        int n = matrix[0].size;

        int pi = 0;
        vector<int> res;
        int dir = 0;
        int offset = 0;
        bool first = false;
        for (int i = 0; i < m * n; i++) {
            if (pi == i) {
                if (!first) {
                    // next round
                } else {
                    res.push_back(matrix[i / n][i % n]);
                }
            }
        }
	}
};

#endif
