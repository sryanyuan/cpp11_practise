#ifndef _INC_SET_MATRIX_ZEROES_
#define _INC_SET_MATRIX_ZEROES_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:


Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]


Example 2:


Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]


Follow up:


	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?

*/

class SetMatrixZeroes {
public:
	static void test() {
		
	}

	static void setZeroes(vector<vector<int>>& matrix) {
        bool rz = false, cz = false;
		int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                cz = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                rz = true;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rz) {
            for (int i = 0; i < m; i++) {
                matrix[0][i] = 0;
            }
        }
        if (cz) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
	}
};

#endif
