#ifndef _INC_ADD_BINARY_
#define _INC_ADD_BINARY_

#include <string>
using std::string;

class AddBinary {
public:
    static string main(string a, string b) {
        if (a.empty() && b.empty()) {
            return string();
        }
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }

        int li = int(a.size());
        int ri = int(b.size());
        int gi = li > ri ? li : ri;
        int bi = li > ri ? li + 1 : ri + 1;
        char* buf = new char[bi + 1];
        buf[bi--] = '\0';
        bool bCarry = false;

        for (int i = 0; i < gi; i++) {
            int lv = 0;
            if (li - 1 - i >= 0) {
                lv = (a[li - 1 - i] == '0' ? 0 : 1);
            }
            int rv = 0;
            if (ri - 1 - i >= 0) {
                rv = (b[ri - 1 - i] == '0' ? 0 : 1);
            }

            int nv = lv + rv;
            if (bCarry) {
                ++nv;
                bCarry = false;
            }

            if (nv == 0) {
                buf[bi--] = '0';
            } else if (nv == 1) {
                buf[bi--] = '1';
            } else if (nv == 2) {
                buf[bi--] = '0';
                bCarry = true;
            } else if (nv == 3) {
                buf[bi--] = '1';
                bCarry = true;
            }
        }

        if (bCarry) {
            buf[bi--] = '1';
        }

        string ret = &buf[bi + 1];

        delete [] buf;
        buf = nullptr;

        return ret;
    }
};

#endif
