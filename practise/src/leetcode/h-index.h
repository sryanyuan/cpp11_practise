#ifndef _INC_H_INDEX_
#define _INC_H_INDEX_

#include "_common_all.h"
#include "_common_list.h"
#include "_common_binary_tree.h"

/* Generated by leetgen (github.com/sryanyuan/leetgen)
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:


Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.
*/

class HIndex {
public:
	static void test() {
		
	}

	static int hIndex(vector<int>& citations) {
		std::sort(citations.rbegin(), citations.rend());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] <= i) {
                return i;
            }
        }
        return citations.size();
	}
};

#endif
