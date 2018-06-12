#ifndef _INC_DETECT_CAPITAL_
#define _INC_DETECT_CAPITAL_

#include <string>
using std::string;

class DetectCapital {
public:
    static bool main(string word) {
        if (word.size() <= 1) {
            return true;
        }
        // 0: case1 all capitals 1:case2 all are not capitals 2:case3 first is capital
        int mode = -1;
        if (word[0] >= 'a' && word[0] <= 'z') {
            if (word[1] >= 'a' && word[1] <= 'z') {
                mode = 1;
            }
        } else {
            if (word[1] >= 'a' && word[1] <= 'z') {
                mode = 2;
            } else {
                mode = 0;
            }
        }
        if (mode < 0) {
            return false;
        }
        for (int i = 2; i < word.size(); i++) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                if (mode == 0) {
                    return false;
                }
            } else {
                if (mode == 1 || mode == 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif
