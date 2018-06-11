#ifndef _INC_LICENSE_KEY_FORMATTING_
#define _INC_LICENSE_KEY_FORMATTING_

#include <string>
using std::string;

class LicenseKeyFormatting {
public:
    static void test() {
        auto ret = main("5F3Z-2e-9-w", 4);
    }

    static string main(string S, int K) {
        string out;
        int dash = std::count(S.begin(), S.end(), '-');
        int left = (S.size() - dash) % K;
        if (0 == left) {
            left = K;
        }
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '-') {
                continue;
            }
            if (0 == left) {
                out.push_back('-');
                left = K;
                i--;
            } else {
                out.push_back(toupper(S[i]));
                left--;
            }
        }
        return out;
    }
};

#endif
