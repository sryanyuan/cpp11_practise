#ifndef _INC_UNIQUE_BINARY_SEARCH_TREES_H
#define _INC_UNIQUE_BINARY_SEARCH_TREES_H

#include "_common_binary_tree.h"

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/

class UniqueBinarySearchTrees : public TreeNodeCls {
public:

    static void test() {
        auto res = numTrees(999);
    }

    static int numTrees(int n) {
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int dpi = 1; dpi <= n; dpi++) {
            int dpv = 0;
            for (int i = 1; i <= dpi; i++) {
                dpv += dp[i - 1] * dp[dpi - i];
            }
            dp[dpi] = dpv;
        }

        return dp[n];
    }
};

#endif
