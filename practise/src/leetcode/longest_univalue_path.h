#ifndef _INC_LONGEST_UNIVALUE_PATH_
#define _INC_LONGEST_UNIVALUE_PATH_

#include "_common_binary_tree.h"

class LongestUnivaluePath : public TreeNodeCls {
public:
    static void test() {
        auto root = stringToTreeNode("[26,26,26,26,26,24,26,25,25,25,27,23,25,25,27,24,26,24,26,24,24,null,28,null,null,26,null,null,26,26,28,25,null,25,27,null,null,null,null,null,23,null,null,29,27,null,null,null,null,25,null,27,27,24,26,24,26,26,26,null,22,28,null,26,26,null,null,26,null,28,28,25,null,null,null,25,25,25,27,25,25,27,25,null,null,null,null,null,null,null,27,27,27,null,null,27,29,24,26,26,26,null,26,null,26,null,null,null,24,24,24,null,26,24,26,null,null,null,26,null,null,null,28,null,30,null,23,27,null,null,null,null,null,null,null,null,null,null,null,23,25,25,25,27,25,23,25,null,null,null,null,null,null,29,null,null,null,26,null,22,null,null,26,24,26,null,26,28,null,null,26,22,null,null,null,null,null,null,null,null,null,null,25,23,null,null,null,null,27]");
        auto ret = main(root);
    }

    static int main(TreeNode *root) {
        int longest = 0;
        walk(root, longest);
        return longest;
    }

    static void walk(TreeNode *node, int &longest) {
        if (nullptr == node) {
            return;
        }
        int cpath = lpath(node, node->val, true) - 1;
        longest = cpath > longest ? cpath : longest;
        walk(node->left, longest);
        walk(node->right, longest);
    }

    static int lpath(TreeNode *node, int pv, bool root) {
        if (node == nullptr || pv != node->val) {
            return 0;
        }
        int ll = lpath(node->left, pv, false);
        int rl = lpath(node->right, pv, false);
        if (root) {
            return ll + rl + 1;
        }
        return ll > rl ? ll + 1 : rl + 1;
    }
};

#endif
