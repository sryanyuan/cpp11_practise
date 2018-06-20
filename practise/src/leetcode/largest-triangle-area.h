#ifndef _INC_LARGEST_TRIANGLE_AREA_
#define _INC_LARGEST_TRIANGLE_AREA_

#include "_common_all.h"
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

class LargestTriangleArea {
public:
	double main(vector<vector<int>>& points) {
		double area = 0;
		for (auto x : points) {
			for (auto y : points) {
				for (auto z : points) {
					area = max(area, 0.5 * abs(x[0] * y[1] + y[0] * z[1] + z[0] * x[1] - y[0] * x[1] - z[0] * y[1] - x[0] * z[1]));
				}
			}
		}
		return area;
	}
};

#endif
