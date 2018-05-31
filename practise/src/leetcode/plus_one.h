#ifndef _INC_PLUS_ONE_
#define _INC_PLUS_ONE_

#include <vector>
#include <algorithm>
using std::vector;

class PlusOne {
public:
    static vector<int> main(vector<int>& digits) {
        vector<int> ret;
        if (digits.size() == 0) {
            return ret;
        }
        ret.reserve(digits.size() + 1);
        int nAdd = 1;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int nNum = digits[i];
            nNum += nAdd;

            if (nNum >= 10) {
                nAdd = 1;
                nNum = 0;
            } else {
                nAdd = 0;
            }
            ret.push_back(nNum);
        }

        if (nAdd != 0) {
            ret.push_back(1);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

#endif
