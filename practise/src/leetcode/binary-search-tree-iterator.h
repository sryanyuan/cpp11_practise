#ifndef _INC_BINARY_SEARCH_TREE_ITERATOR_
#define _INC_BINARY_SEARCH_TREE_ITERATOR_

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

#include "_common_binary_tree.h"

class BinarySearchTreeIterator : public TreeNodeCls {
public:
    BSTIterator(TreeNode *root) {
        while (nullptr != root) {
            stk_.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk_.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = stk_.top();
        stk_.pop();
        int val = node->val;
        node = node->right;
        while (nullptr != node) {
            stk_.push(node);
            node = node->left;
        }
        return val;
    }

    stack<TreeNode*> stk_;
};

#endif
