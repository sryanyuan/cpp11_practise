#ifndef _INC_CONVERT_A_NUMBER_TO_HEXADEMICAL_
#define _INC_CONVERT_A_NUMBER_TO_HEXADEMICAL_

#include <string>
using std::string;

class ConvertANumberToHexdemical {
public:
    static void test() {
        auto ret = main(16);
    }

    static string main(int num) {
        if (num == 0) {
            return "0";
        }

        string ret;
        for (int i = 0; i < 8; i++) {
            // Read the high 4 bit
            uint32_t val = num & 0xf0000000;
            val = val >> 28;
            if (val != 0 || !ret.empty()) {
                if (val < 10) {
                    ret += std::to_string(val);
                } else {
                    ret += 'a' + val - 10;
                }
            }
            
            num = num << 4;
        }

        return ret;
    }
};

#endif
