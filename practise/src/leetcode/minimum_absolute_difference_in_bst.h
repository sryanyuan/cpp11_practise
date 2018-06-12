#ifndef _INC_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_
#define _INC_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_

#include "_common_binary_tree.h"
#include <vector>
using std::vector;
#include <algorithm>

class MinimumAbsoluteDifferenceInBST : public TreeNodeCls {
public:
    static int preorder(TreeNode *root) {
        int diff = INT_MAX;
        int tail = -1;
        walk(root, diff, tail);
        return diff;
    }

    static void walk(TreeNode *node, int &diff, int &tail) {
        if (nullptr == node) {
            return;
        }
        // Left node < node, node < right node
        if (nullptr != node->left) {
            walk(node->left, diff, tail);
        }
        if (tail >= 0) {
            int v = abs(node->val - tail);
            if (v < diff) {
                diff = v;
            }
        }
        // Here we record the last visit node's value (largest in current visited nodes)
        tail = node->val;
        if (nullptr != node->right) {
            walk(node->right, diff, tail);
        }
    }

    static int main(TreeNode *root) {
        vector<int> vals;
        walk(root, vals);
        std::sort(vals.begin(), vals.end());

        int diff = INT_MAX;
        for (int i = 1; i < vals.size(); i++) {
            int v = abs(vals[i] - vals[i - 1]);
            if (v < diff) {
                diff = v;
            }
        }
        return diff;
    }

    static void walk(TreeNode *node, vector<int> &vals) {
        if (nullptr == node) {
            return;
        }
        vals.push_back(node->val);
        if (nullptr != node->left) {
            walk(node->left, vals);
        }
        if (nullptr != node->right) {
            walk(node->right, vals);
        }
    }
};

#endif
