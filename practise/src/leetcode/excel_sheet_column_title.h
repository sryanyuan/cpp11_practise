#ifndef _INC_EXCEL_SHEET_COLUMN_TITLE_
#define _INC_EXCEL_SHEET_COLUMN_TITLE_

#include <string>
using std::string;

class ExcelSheetColumnTitle {
public:
    static void test() {
        auto ret = main(701);
    }

    static string main(int n) {
        const int ratio = 26;
        string ret;
        
        while (n > 0) {
            if (n <= ratio) {
                ret.push_back('A' + n - 1);
                break;
            }
            int quotient = n / ratio;
            int reminder = n - quotient * ratio;
            if (0 == reminder) {
                n -= ratio;
                n /= ratio;
                ret.push_back('Z');
            } else {
                n = (n - reminder) / ratio;
                ret.push_back('A' + reminder - 1);
            }
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

#endif
