#ifndef _INC_BINARY_WATCH_
#define _INC_BINARY_WATCH_

#include <vector>
#include <string>
using std::vector;
using std::string;
#include <stdio.h>

class BinaryWatch {
public:
    static void test() {
        auto ret = main(1);
    }

    static vector<string> main(int num) {
        if (num > 10) {
            num = 10;
        }
        int numBits[60] = {0};
        vector<vector<int>> bitNum;
        bitNum.resize(10);
        bitNum[0].push_back(0);
        for (int i = 1; i < sizeof(numBits) / sizeof(numBits[0]); i++) {
            int v = i;
            int cnt = 1;
            v = v & (v - 1);
            while (v != 0) {
                cnt++;
                v = v & (v - 1);
            }
            numBits[i] = cnt;
            bitNum[cnt].push_back(i);
        }

        vector<string> rets;
        for (int hour = 0; hour < 12; hour++) {
            int hourBit = numBits[hour];
            if (hourBit > num) {
                continue;
            }

            int minuteBit = num - hourBit;
            for (auto minute : bitNum[minuteBit]) {
                // Make time string
                char szBuf[10];
                sprintf(szBuf, "%d:%02d", hour, minute);
                rets.push_back(szBuf);
            }
        }

        return rets;
    }
};

#endif
