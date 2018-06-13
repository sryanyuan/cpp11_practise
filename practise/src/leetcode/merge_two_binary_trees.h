#ifndef _INC_MERGE_TWO_BINARY_TREES_
#define _INC_MERGE_TWO_BINARY_TREES_

#include "_common_binary_tree.h"

class MergeTwoBinaryTrees : public TreeNodeCls {
public:
    static void test() {
        auto t1 = stringToTreeNode("[9,-1,null,-2,0,-4,null,null,8,-5,-3,6,null,null,null,null,null,null,7]");
        auto t2 = stringToTreeNode("[-1,-2,0,null,null,null,8,6,null,null,7]");
        auto ret = treeNodeToString(main(t1, t2));
    }

    static TreeNode* main(TreeNode *t1, TreeNode *t2) {
        if (nullptr == t1 && nullptr != t2) {
            t1 = t2;
            t2 = nullptr;
        }
        walk(t1, t2);
        return t1;
    }

    static void walk(TreeNode *t1, TreeNode *t2) {
        if (nullptr == t1 || nullptr == t2) {
            return;
        }
        t1->val += t2->val;
        if (t1->left == nullptr && t2->left != nullptr) {
            t1->left = t2->left;
            t2->left = nullptr;
        }
        if (t1->right == nullptr && t2->right != nullptr) {
            t1->right = t2->right;
            t2->right = nullptr;
        }
        walk(t1->left, t2->left);
        walk(t1->right, t2->right);
    }
};

#endif
