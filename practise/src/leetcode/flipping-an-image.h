#ifndef _INC_FLIPPING_AN_IMAGE_
#define _INC_FLIPPING_AN_IMAGE_

#include "_common_all.h"

class FlippingAnImage {
public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &row : A) {
            convertRow(row);
        }
        return A;
    }

    static void convertRow(vector<int>& row) {
        for (int i = 0; i < (row.size() + 1 ) / 2; i++) {
            int mid = (row[i] == 1 ? 0 : 1);
            row[i] = (row[row.size() - 1 - i] == 1 ? 0 : 1);
            row[row.size() - 1 - i] = mid;
        }
    }
};

#endif
