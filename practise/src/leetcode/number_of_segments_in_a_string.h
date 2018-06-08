#ifndef _INC_NUMBER_OF_SEGMENTS_IN_A_STRING_
#define _INC_NUMBER_OF_SEGMENTS_IN_A_STRING_

#include <string>
using std::string;

class NumberOfSegmentsInAString {
public:
    static void test() {
        auto ret = main("Hello, my name is John");
    }

    static int main(string s) {
        int cnt = 0;
        int seq = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                cnt++;
            } else {
                if (cnt != 0) {
                    seq++;
                    cnt = 0;
                }
            }
        }
        if (cnt != 0) {
            seq++;
        }
        return seq;
    }
};

#endif
