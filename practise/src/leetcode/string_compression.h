#ifndef _INC_STRING_COMPRESSION_
#define _INC_STRING_COMPRESSION_

#include <vector>
using std::vector;
#include <string>
using std::string;

class StringCompression {
public:
    static void test() {
        string s = "abbbbbbbbbbb";
        vector<char> chars(s.size());
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        auto ret = main(chars);
    }

    static int main(vector<char>& chars) {
        if (chars.size() == 1) {
            return 1;
        }

        char pre = chars[0];
        unsigned short cnt = 1;
        unsigned short nextcarry = 10;
        char carrybit = 0;
        int len = 0;
        int inserti = 0;

        chars.push_back(0);

        for (int i = 1; i < chars.size(); i++) {
            if (pre == chars[i]) {
                cnt++;
                if (cnt >= nextcarry) {
                    carrybit++;
                    nextcarry *= 10;
                }
                continue;
            }
            if (cnt > 1) {
                len += (1 + carrybit + 1);
                chars[inserti++] = pre;
                if (cnt < 10) {
                    chars[inserti++] = '0' + cnt;
                } else {
                    string ns = std::to_string(cnt);
                    for (int j = 0; j < ns.size(); j++) {
                        chars[inserti++] = ns[j];
                    }
                }
            } else {
                len++;
                chars[inserti++] = pre;
            }
            carrybit = 0; nextcarry = 10;
            pre = chars[i];
            cnt = 1;
        }

        if (len < chars.size()) {
            chars.resize(len);
            return len;
        }
        return chars.size();
    }
};

#endif
