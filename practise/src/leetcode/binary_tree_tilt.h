#ifndef _INC_BINARY_TREE_TILT_
#define _INC_BINARY_TREE_TILT_

#include "_common_binary_tree.h"

class BinaryTreeTilt : public TreeNodeCls {
public:
    static int main(TreeNode *root) {
        int sum = 0;
        int tsum = 0;
        walk(root, sum, tsum);
        return tsum;
    }

    static void walk(TreeNode *node, int &sum, int &tsum) {
        if (nullptr == node) {
            return;
        }
        int lsum = 0;
        int rsum = 0;
        if (nullptr != node->left) {
            walk(node->left, lsum, tsum);
        }
        if (nullptr != node->right) {
            walk(node->right, rsum, tsum);
        }
        tsum += abs(lsum - rsum);
        sum += (lsum + rsum + node->val);
    }
};

#endif
