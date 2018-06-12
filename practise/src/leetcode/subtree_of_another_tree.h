#ifndef _INC_SUBTREE_OF_ANOTHER_TREE_
#define _INC_SUBTREE_OF_ANOTHER_TREE_

#include "_common_binary_tree.h"
#include <vector>
using std::vector;

class SubtreeOfAnotherTree : public TreeNodeCls {
public:
    static void test() {
        auto ret = traversal(stringToTreeNode("[3,4,5,1,2,null,null,0]"),
            stringToTreeNode("[4,1,2]"));
    }

    static bool traversal(TreeNode *s, TreeNode *t) {
        bool sub = false;
        walk(s, t, sub);
        return sub;
    }

    static void walk(TreeNode *s, TreeNode *t, bool &sub) {
        if (sub) {return;}
        if (nullptr == s) {return;}
        bool same = true;
        compare(s, t, same);
        if (same) {sub = true; return;}
        walk(s->left, t, sub);
        walk(s->right, t, sub);
    }

    static void compare(TreeNode *s, TreeNode *t, bool &same) {
        if (!same) {return;}
        if (nullptr == s && nullptr == t) {
            return;
        }
        if (nullptr == s && nullptr != t) {
            same = false;
            return;
        }
        if (nullptr == t && nullptr != s) {
            same = false;
            return;
        }
        
        if (s->val != t->val) {
            same = false;
            return;
        }
        compare(s->left, t->left, same);
        compare(s->right, t->right, same);
    }

    static bool main(TreeNode *s, TreeNode *t) {
        vector<int> svs;
        vector<int> tvs;
        walk(s, svs);
        walk(t, tvs);
        if (tvs.size() > svs.size()) {
            return false;
        }
        for (int i = 0; i <= svs.size() - tvs.size(); i++) {
            int j = 0;
            for (j = 0; j < tvs.size(); j++) {
                if (tvs[j] != svs[i + j]) {break;}
            }
            if (j >= tvs.size()) {return true;}
        }
        return false;
    }

    static void walk(TreeNode *node, vector<int>& vals) {
        if (nullptr == node) {
            vals.push_back(0);
            return;
        }
        vals.push_back(node->val);
        walk(node->left, vals);
        walk(node->right, vals);
    }
};

#endif
