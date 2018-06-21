#ifndef _INC_RECTANGLE_OVERLAP_
#define _INC_RECTANGLE_OVERLAP_

#include "_common_all.h"

class RectangleOverlap {
public:
    static bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec2[2] <= rec1[0] ||
            rec2[0] >= rec1[2] ||
            rec2[1] >= rec1[3] ||
            rec2[3] <= rec1[1]) {
                return false;
        }
        return true;
    }
};

#endif
