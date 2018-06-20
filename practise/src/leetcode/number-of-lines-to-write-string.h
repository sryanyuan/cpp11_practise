#ifndef _INC_NUMBER_OF_LINES_TO_WRITE_STRING_
#define _INC_NUMBER_OF_LINES_TO_WRITE_STRING_

#include "_common_all.h"

class NumberOfLinesToWriteString {
public:
    static vector<int> main(vector<int>& widths, string S) {
        vector<int> ret(2);
        int line = 1;
        int lw = 0;
        const int maxWidth = 100;
        for (auto c : S) {
            int w = widths[c - 'a'];
            lw += w;
            if (lw > maxWidth) {
                ++line;
                lw = w;
            }
        }
        ret[0] = line;
        ret[1] = lw;
        return ret;
    }
};

#endif
