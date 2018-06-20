#ifndef _INC_MINIMUM_DISTANCE_BETWEEN_BST_NONES_
#define _INC_MINIMUM_DISTANCE_BETWEEN_BST_NONES_

#include "_common_binary_tree.h"

class MinimumDistanceBetweenBstNodes : public TreeNodeCls {
public:
    static int main(TreeNode* root) {
        stack<int> vals;
        walk(root, vals);
        int ret = 0;
        int pv = vals.top();
        vals.pop();
        while (!vals.empty()) {
            int cv = vals.top();
            vals.pop();
            if (0 == ret || abs(cv - pv) < ret) {
                ret = abs(cv - pv);
            }
            pv = cv;
        }
        return ret;
    }

    static void walk(TreeNode *node, stack<int> &vals) {
        if (nullptr == node) {
            return;
        }
        walk(node->left, vals);
        vals.push(node->val);
        walk(node->right, vals);
    }
};

#endif
