#ifndef _INC_ADD_STRINGS_
#define _INC_ADD_STRINGS_

#include <string>
using std::string;
#include <algorithm>

class AddStrings {
public:
    static void test() {
        auto ret = main("128", "683");
    }

    static string main(string num1, string num2) {
        string ret;
        bool carry = false;
        int nm = num1.size() > num2.size() ? num1.size() : num2.size();

        for (int i = 0; i < nm; i++) {
            int li = num1.size() - 1 - i;
            int ri = num2.size() - 1 - i;
            int sum = 0;

            if (li >= 0) {
                sum += num1[li] - '0';
            }
            if (ri >= 0) {
                sum += num2[ri] - '0';
            }
            if (carry) {
                sum++;
                carry = false;
            }
            if (sum >= 10) {
                sum -= 10;
                carry = true;
            }
            ret += std::to_string(sum);
        }
        if (carry) {
            ret += "1";
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

#endif
