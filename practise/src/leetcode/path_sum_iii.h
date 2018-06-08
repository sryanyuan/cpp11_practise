#ifndef _INC_PATH_SUM_III_
#define _INC_PATH_SUM_III_

#include <vector>
using std::vector;
#include "_common_binary_tree.h"

class PathSumIII : public TreeNodeCls {
public:
    static void test() {
        TreeNode* root = stringToTreeNode("[10,5,-3,3,2,null,11,3,-2,null,1]");
        auto ret = main(root, 8);
    }

    static int main(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }

        vector<int> parentVals;
        int cnt = 0;
        walk(root, parentVals, sum, cnt);
        return cnt;
    }

    static void walk(TreeNode* node, vector<int>& pvs, int sum, int& cnt) {
        if (nullptr == node) {
            return;
        }

        vector<int> cvs(pvs.begin(), pvs.end());
        cvs.push_back(node->val);
        // Check sum
        int cur = 0;
        for (int i = cvs.size() - 1; i >= 0; i--) {
            cur += cvs[i];
            if (cur == sum) {
                ++cnt;
            }
        }
        // Walk the left and right sub tree
        if (nullptr != node->left) {
            walk(node->left, cvs, sum, cnt);
        }
        if (nullptr != node->right) {
            walk(node->right, cvs, sum, cnt);
        }
    }
};

#endif
