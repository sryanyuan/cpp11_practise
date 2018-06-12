#ifndef _INC_RESHAPE_THE_MATRIX_
#define _INC_RESHAPE_THE_MATRIX_

#include <vector>
using std::vector;

class ReshapeTheMatrix {
public:
    static void test() {
        vector<vector<int>> nums;
        vector<int> row;
        row.push_back(1);
        row.push_back(2);
        row.push_back(3);
        row.push_back(4);
        nums.push_back(row);
        auto ret = main(nums, 2, 2);
    }

    static vector<vector<int>> main(vector<vector<int>>& nums, int r, int c) {
        int ocnt = 0;
        int orow = 0, ocol = 0;
        for (auto &row : nums) {
            orow = nums.size();
            ocol = row.size();
            ocnt = orow * ocol;
        }
        if (0 == ocnt || r * c != ocnt) {
            return nums;
        }

        vector<vector<int>> rets;
        for (int i = 0; i < r; i++) {
            vector<int> nrow;
            nrow.resize(c);
            for (int j = 0; j < c; j++) {
                int seq = c * i + j;
                nrow[j] = nums[seq / ocol][seq % ocol];
            }
            rets.push_back(std::move(nrow));
        }
        return rets;
    }
};

#endif
