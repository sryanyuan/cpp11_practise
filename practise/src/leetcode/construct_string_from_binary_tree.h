#ifndef _INC_CONSTRUCT_STRING_FROM_BINARY_TREE_
#define _INC_CONSTRUCT_STRING_FROM_BINARY_TREE_

#include "_common_all.h"
#include "_common_binary_tree.h"

class ConstructStringFromBinaryTree : public TreeNodeCls {
public:
    static void test() {
        auto ret = main(stringToTreeNode("[1,2,3,null,4]"));
    }

    static string main(TreeNode *t) {
        string str;
        walk(t, str);
        return str;
    }

    static void walk(TreeNode *t, string &str) {
        if (nullptr == t) {
            return;
        }
        str += std::to_string(t->val);
        if (nullptr == t->left && nullptr == t->right) {
            return;
        }
        if (nullptr == t->left) {
            str += "()";
        } else {
            str += "(";
            walk(t->left, str);
            str += ")";
        }
        if (nullptr != t->right) {
            str += "(";
            walk(t->right, str);
            str += ")";
        }
    }
};

#endif
