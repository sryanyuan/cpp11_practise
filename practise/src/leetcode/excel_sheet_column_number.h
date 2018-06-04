#ifndef _INC_EXCEL_SHEET_COLUMN_NUMBER_
#define _INC_EXCEL_SHEET_COLUMN_NUMBER_

#include <string>
using std::string;

class ExcelSheetColumnNumber {
public:
    static void test() {
        auto ret = main("ZY");
    }

    static int main(string s) {
        int ratio = 1;
        int value = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int n = int(s[i]) - 'A' + 1;
            value += ratio * n;
            ratio *= 26;
        }

        return value;
    }
};

#endif
