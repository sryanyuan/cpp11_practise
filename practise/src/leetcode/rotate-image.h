#ifndef _INC_ROTATE_IMAGE_
#define _INC_ROTATE_IMAGE_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generate by leetgen (github.com/sryanyuan/leetgen)
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:


Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]


Example 2:


Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

class RotateImage {
public:
	static void test() {
		vector<vector<int>> matrix;
        vector<int> row;
        row.push_back(5);
        row.push_back(1);
        row.push_back(9);
        row.push_back(11);
        matrix.push_back(std::move(row));
        row.push_back(2);
        row.push_back(4);
        row.push_back(8);
        row.push_back(10);
        matrix.push_back(std::move(row));
        row.push_back(13);
        row.push_back(3);
        row.push_back(6);
        row.push_back(7);
        matrix.push_back(std::move(row));
        row.push_back(15);
        row.push_back(14);
        row.push_back(12);
        row.push_back(16);
        matrix.push_back(std::move(row));
        rotate(matrix);
	}

	static void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
        int offset = 0;
        for (offset; offset < n / 2; offset++) {
            int i = offset;
            int j = offset;
            
            for (j; j < n - 1 - offset; j++) {
                int ni = i, nj = j;
                int pv = matrix[i][j];
                for (int dir = 0; dir < 4; dir++) {
                    move(ni, nj, n, offset, dir);
                    int val = matrix[ni][nj];
                    matrix[ni][nj] = pv;
                    pv = val;
                }
            }
        }
	}

    static void move(int &i, int &j, int n, int offset, int dir) {
        int w = n - 2 * offset;
        if (dir == 0) {
            j += (w - 1);
            if (j >= n - 1 - offset) {
                int left = j - (n - 1 - offset);
                j = n - 1 - offset;
                i += left;
            }
        } else if (dir == 1) {
            i += (w - 1);
            if (i >= n - 1 - offset) {
                int left = i - (n - 1 - offset);
                i = n - 1 - offset;
                j -= left;
            }
        } else if (dir == 2) {
            j -= (w - 1);
            if (j < offset) {
                int left = offset - j;
                j = offset;
                i -= left;
            }
        } else {
            i -= (w - 1);
            if (i < offset) {
                int left = offset - i;
                i = offset;
                j += left;
            }
        }
    }
};

#endif
