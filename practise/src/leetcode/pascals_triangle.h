#ifndef _INC_PASCALS_TRIANGLE_
#define _INC_PASCALS_TRIANGLE_

#include <vector>
using std::vector;

class PascalsTriangle {
public:
    static void test() {
        auto rets = main(5);
    }

    static vector<vector<int>> main(int numRows) {
        if (0 == numRows) {
            return vector<vector<int>>();
        }

        vector<vector<int>> rows;
        vector<int> row;
        row.push_back(1);
        rows.push_back(std::move(row));
        vector<int>* prevRow = &rows[0];

        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j < i + 1; j++) {
                int si = j - 1;
                int ei = j;
                int sv = 0;
                int ev = 0;
                if (si >= 0 && si < prevRow->size()) {
                    sv = (*prevRow)[si];
                }
                if (ei >= 0 && ei < prevRow->size()) {
                    ev = (*prevRow)[ei];
                }
                row.push_back(sv + ev);
            }

            rows.push_back(std::move(row));
            prevRow = &rows[rows.size() - 1];
        }

        return rows;
    }
};

#endif
