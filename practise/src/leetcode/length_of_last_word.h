#ifndef _INC_LENGTH_OF_LAST_WORD_
#define _INC_LENGTH_OF_LAST_WORD_

#include <string>
using std::string;

class LengthOfLastWord {
public:
    static int main(string s) {
        size_t uLen = s.size();
        if (uLen == 0) {
            return 0;
        }
        int nCnt = 0;
        bool bEnd = true;

        for (int i = int(uLen) - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (bEnd) {
                    continue;
                }
                break;
            }
            bEnd = false;
            nCnt++;
        }
        return nCnt;
    }
};

#endif
