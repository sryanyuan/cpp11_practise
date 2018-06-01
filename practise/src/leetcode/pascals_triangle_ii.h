#ifndef _INC_PASCALS_TRIANGLE_II_
#define _INC_PASCALS_TRIANGLE_II_

#include <vector>
using std::vector;

class PascalsTriangleII {
public:
    static void test() {
        auto ret = main(30);
    }

    static vector<int> main(int rowIndex) {
        // row[i] = row[i - 1] * (rowIndex - i + 1) / i
        vector<int> row;
        row.resize(rowIndex + 1);
        row[0] = 1;
        row[rowIndex] = 1;

        for (int i = 1; i < (row.size() + 1) / 2; i++) {
            long long v = (long long)row[i - 1] * (long long)(rowIndex - i + 1) / (long long)i;
            row[i] = v; row[rowIndex - i] = v;
        }
        return row;
    }
};

#endif
