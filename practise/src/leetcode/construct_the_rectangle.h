#ifndef _INC_CONSTRUCT_THE_RECTANGLE_
#define _INC_CONSTRUCT_THE_RECTANGLE_

#include <vector>
using std::vector;

class ConstructTheRectangle {
public:
    static void test() {
        auto ret = main(4);
    }

    static vector<int> main(int area) {
        int ret = sqrt(area);
        vector<int> rets;
        rets.resize(2);
        int w = ret;

        for (;;) {
            if (area % w == 0) {
                rets[0] = area / w;
                rets[1] = w;
                return rets;
            }
            w--;
        }
    }
};

#endif
