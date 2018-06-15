#ifndef _INC_IMAGE_SMOOTHER_
#define _INC_IMAGE_SMOOTHER_

#include "_common_all.h"

class ImageSmoother {
public:
    static vector<vector<int>> main(vector<vector<int>>& M) {
        int row = M.size();
        if (0 == row) {return M;};
        int col = 0;
        static int offset[] = {0, 0, -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
        vector<vector<int>> ret = M;

        for (int i = 0; i < row; i++) {
            if (0 == col) {
                col = M[i].size();
                if (0 == col) {
                    return M;
                }
            }
            for (int j = 0; j < col; j++) {
                int sum = 0;
                int cnt = 0;
                for (int oi = 0; oi < sizeof(offset) / sizeof(offset[0]); oi += 2) {
                    int ri = i + offset[oi];
                    int rj = j + offset[oi + 1];
                    if (rj < col && ri < row &&
                        rj >= 0 && ri >= 0) {
                            sum += M[ri][rj];
                            cnt++;
                    }
                }
                ret[i][j] = sum / cnt;
            }
        }

        return ret;
    }
};

#endif
