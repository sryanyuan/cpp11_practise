#ifndef _INC_COUNT_AND_SAY_
#define _INC_COUNT_AND_SAY_

#include <string>
using std::string;
#include <sstream>
using std::stringstream;

class CountAndSay {
public:
    static string main(int n) {
        if (0 == n) {
            return "";
        }

        string out = "1";

        for (int i = 2; i <= n; i++) {
            // Do count
            char cPrev = 0;
            int nCnt = 0;
            int nIndex = 0;
            stringstream ss;

            for (nIndex; nIndex < out.size(); nIndex++) {
                char ch = out[nIndex];
                if (cPrev == 0) {
                    cPrev = ch;
                    ++nCnt;
                } else {
                    if (cPrev == ch) {
                        ++nCnt;
                    } else {
                        ss << nCnt << cPrev;
                        cPrev = ch;
                        nCnt = 1;
                    }
                }
            }

            if (cPrev != 0) {
                ss << nCnt << cPrev;
            }

            out = ss.str();
        }

        return out;
    }
};

#endif
