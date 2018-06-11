#ifndef _INC_BASE_7_
#define _INC_BASE_7_

#include <string>
using std::string;

class Base7 {
public:
    static void test() {
        auto ret = main(-1e7);
    }

    static string main(int num) {
        string ret;
        if (num == 0) {
            return "0";
        }
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        while (num != 0) {
            int val = num % 7;
            ret.push_back('0' + val);
            num = (num - val) / 7;
        }
        if (neg) {
            ret.push_back('-');
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

#endif
