#ifndef _INC_TRAPPING_RAIN_WATER_
#define _INC_TRAPPING_RAIN_WATER_

#include <vector>
using std::vector;

class TrappingRainWater {
public:
	static void test() {
		vector<int> height;
		int nums[] = { 4,2,3 };
		for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
			height.push_back(nums[i]);
		}
		auto ret = quick(height);
	}

	static int quick(vector<int>& height) {
		if (height.size() == 0) {
			return 0;
		}
		int m = height[0];
		int mi = 0;
		int sum = 0;

		for (int i = 1; i < height.size(); i++) {
			if (height[i] >= m) {
				m = height[i];
				mi = i;
			}
		}

		int ml = mi;
		int mr = mi;
		int l = search(height, ml, true);
		int r = search(height, mr, false);

		while (ml != l || mr != r) {
			if (ml != l) {
				for (int i = l + 1; i < ml; i++) {
					sum += height[l] - height[i];
				}
				ml = l;
				l = search(height, ml, true);
			}
			if (mr != r) {
				for (int i = mr + 1; i < r; i++) {
					sum += height[r] - height[i];
				}
				mr = r;
				r = search(height, mr, false);
			}
		}

		return sum;
	}

	static int search(vector<int>& height, int vi, bool left) {
		int num = -1;
		int ni = vi;

		if (left) {
			for (int i = 0; i < vi; i++) {
				if (height[i] >= num) {
					ni = i;
					num = height[i];
				}
			}
		}
		else {
			for (int i = vi + 1; i < height.size(); i++) {
				if (height[i] >= num) {
					ni = i;
					num = height[i];
				}
			}
		}

		return ni;
	}

	static int main(vector<int>& height) {
		int l = 0;
		int r = height.size() - 1;
		int sum = 0;
		int prem = 0;

		while (l < r) {
			// Find all less than min(l, r)
			int m = height[l] < height[r] ? height[l] : height[r];
			for (int i = l + 1; i <= r - 1; i++) {
				if (height[i] < m) {
					int ml = m - prem < 0 ? 0 : m - prem;
					int mr = height[i] - prem < 0 ? 0 : height[i] - prem;
					sum += ml - mr;
				}
			}
			prem = m;
			// Move left && right to next position
			if (height[l] > height[r])
			{
				for (r; r >= l; r--) {
					if (height[r] > m) {
						break;
					}
				}
			}
			else if (height[l] < height[r])
			{
				for (l; l <= r; l++) {
					if (height[l] > m) {
						break;
					}
				}
			}
			else
			{
				for (l; l <= r; l++) {
					if (height[l] > m) {
						break;
					}
				}
				for (r; r >= l; r--) {
					if (height[r] > m) {
						break;
					}
				}
			}
		}

		return sum;
	}
};

#endif
