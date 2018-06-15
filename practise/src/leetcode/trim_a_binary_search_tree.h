#ifndef _INC_TRIM_A_BINARY_SEARCH_TREE_
#define _INC_TRIM_A_BINARY_SEARCH_TREE_

#include "_common_binary_tree.h"

class TrimABinarySearchTree : public TreeNodeCls {
public:
    static void test() {
        auto root = stringToTreeNode("[3,0,4,null,2,null,null,1]");
        auto nt = main(root, 1,3);
        auto ret = treeNodeToString(nt);
    }

    static TreeNode * main(TreeNode *root, int L, int R) {
        if (nullptr == root) {
            return nullptr;
        }
        TreeNode * nt = new TreeNode(0);
        bool ini = true;
        walk(root, L, R, nt, ini);
        if (ini) {
            return nullptr;
        }
        return nt;
    }

    static void walk(TreeNode *subtree, int L, int R, TreeNode *nt, bool &ini) {
        if (nullptr == subtree) {
            return;
        }
        if (subtree->val >= L && subtree->val <= R) {
            // Append to new tree
            if (ini) {
                ini = false;
                nt->val = subtree->val;
                walk(subtree->left, L, R, nt, ini);
                walk(subtree->right, L, R, nt, ini);
            } else {
                if (subtree->val < nt->val) {
                    nt->left = new TreeNode(subtree->val);
                    walk(subtree->left, L, R, nt->left, ini);
                    walk(subtree->right, L, R, nt->left, ini);
                } else {
                    nt->right = new TreeNode(subtree->val);
                    walk(subtree->left, L, R, nt->right, ini);
                    walk(subtree->right, L, R, nt->right, ini);
                }
            }
        } else {
            if (subtree->val > L) {
                walk(subtree->left, L, R, nt, ini);
            }
            if (subtree->val < R) {
                walk(subtree->right, L, R, nt, ini);
            }
        }
    }
};

#endif
