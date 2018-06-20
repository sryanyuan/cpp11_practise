#ifndef _INC_TOEPLITZ_MATRIX_
#define _INC_TOEPLITZ_MATRIX_

#include "_common_all.h"

class ToeplitzMatrix {
public:
    static bool main(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int r = 0; r < row - 1; r++) {
            for (int c = 0; c < col - 1; c++) {
                int nr = r + 1;
                int nc = c + 1;
                if (nr < row && nc < col && matrix[nr][nc] != matrix[r][c]) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif
