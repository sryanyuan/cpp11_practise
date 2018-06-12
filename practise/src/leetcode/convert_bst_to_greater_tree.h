#ifndef _INC_CONVERT_BST_TO_GREATER_TREE_
#define _INC_CONVERT_BST_TO_GREATER_TREE_

#include "_common_binary_tree.h"

class ConvertBSTToGreaterTree : public TreeNodeCls {
public:
    static TreeNode* main(TreeNode *root) {
        int sum = 0;
        walk(root, &sum);
        return root;
    }

    static void walk(TreeNode *node, int *sum) {
        if (nullptr == node) {
            return;
        }
        if (nullptr != node->right) {
            walk(node->right, sum);
        }
        int val = node->val;
        node->val += *sum;
        *sum += val;
        if (nullptr != node->left) {
            walk(node->left, sum);
        }
    }
};

#endif
