#ifndef _INC_FLOOD_FILL_
#define _INC_FLOOD_FILL_

#include "_common_all.h"

class FloodFill {
public:
    static void test() {
        vector<vector<int>> image;
        vector<int> row;
        row.push_back(1);
        row.push_back(1);
        row.push_back(1);
        image.push_back(std::move(row));
        row.push_back(1);
        row.push_back(1);
        row.push_back(0);
        image.push_back(std::move(row));
        row.push_back(1);
        row.push_back(0);
        row.push_back(1);
        image.push_back(std::move(row));
        auto ret = main(image, 1, 1, 2);
    }

    static vector<vector<int>> main(vector<vector<int>>& image, int sr, int sc, int newColor) {
        unordered_set<int> hitpos;
        ffill(image, sr, sc, image[sr][sc], newColor, hitpos);
        return image;
    }

    static void ffill(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor, unordered_set<int> &hitpos) {
        static int offsets[] = {0, -1, 0, 1, -1, 0, 1, 0};
        int row = image.size();
        int col = image[0].size();
        if (sr < 0 || sr >= row || sc < 0 || sc >= col) {
            return;
        }
        if (hitpos.count(sr << 8 | sc) != 0) {
            return;
        }
        if (image[sr][sc] != oldColor) {
            return;
        }
        hitpos.insert(sr << 8 | sc);
        image[sr][sc] = newColor;

        for (int i = 0; i < sizeof(offsets) / sizeof(offsets[0]); i += 2) {
            ffill(image, sr + offsets[i], sc + offsets[i + 1], oldColor, newColor, hitpos);
        }
    }
};

#endif
