#ifndef INC_ISLAND_PERIMETER_
#define INC_ISLAND_PERIMETER_

#include <vector>
using std::vector;

class IslandPerimeter {
public:
    static void test() {
        vector<vector<int>> grid;
        vector<int> row;
        row.push_back(1);
        row.push_back(0);
        grid.push_back(row);
        auto ret = main(grid);
    }
    
    static int main(vector<vector<int>>& grid) {
        int row = 0, col = 0;
        int rsize = grid.size();
        int csize = 0;
        int perimeter = 0;

        for (row; row < rsize; row++) {
            vector<int>& grow = grid[row];
            csize = grow.size();
            for (col = 0; col < csize; col++) {
                if (grid[row][col] == 0) {
                    continue;
                }
                // up
                if (row == 0) {
                    ++perimeter;
                } else {
                    if (0 == grid[row - 1][col]) {
                        ++perimeter;
                    }
                }
                // bottom
                if (row == rsize - 1) {
                    ++perimeter;
                } else {
                    if (0 == grid[row + 1][col]) {
                        ++perimeter;
                    }
                }
                // left
                if (col == 0) {
                    ++perimeter;
                } else {
                    if (0 == grid[row][col - 1]) {
                        ++perimeter;
                    }
                }
                // right
                if (col == csize - 1) {
                    ++perimeter;
                } else {
                    if (0 == grid[row][col + 1]) {
                        ++perimeter;
                    }
                }
            }
        }
        return perimeter;
    }
};

#endif
