#ifndef _INC_DIAMETER_OF_BINARY_TREE_
#define _INC_DIAMETER_OF_BINARY_TREE_

#include "_common_binary_tree.h"

class DiameterOfBinaryTree : public TreeNodeCls {
public:
    static void test() {
        auto root = stringToTreeNode("[1,2,3,4,5]");
        auto ret = main(root);
    }

    static int main(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int len = 0;
        int mlen = 0;
        walk(root, len, mlen);
        return mlen - 1;
    }

    static void walk(TreeNode *node, int &len, int &mlen) {
        if (nullptr == node) {
            return;
        }
        int llen = 0;
        int rlen = 0;
        if (nullptr != node->left) {
            walk(node->left, llen, mlen);
        }
        if (nullptr != node->right) {
            walk(node->right, rlen, mlen);
        }
        len = (llen > rlen ? llen : rlen) + 1;
        if (llen + rlen + 1 > mlen) {
            mlen = llen + rlen + 1;
        }
    }
};

#endif
