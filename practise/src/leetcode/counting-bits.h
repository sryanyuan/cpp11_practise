#ifndef _INC_COUNTING_BITS_
#define _INC_COUNTING_BITS_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.


Example:
For num = 5 you should return [0,1,1,2,1,2].


Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.



Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.*/

class CountingBits {
public:
	static void test() {
		
	}

	static vector<int> countBits(int num) {
		vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            int val = (i - 1) & i;
            int cnt = 0;
            while (val != 0) {
                val &= (val - 1);
                ++cnt;
            }
            res[i] = cnt + 1;
        }
        return res;
	}
};

#endif
