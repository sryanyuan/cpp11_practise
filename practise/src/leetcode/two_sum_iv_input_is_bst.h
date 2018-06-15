#ifndef _INC_TWO_SUM_IV_INPUT_IS_BST_
#define _INC_TWO_SUM_IV_INPUT_IS_BST_

#include "_common_binary_tree.h"

class TwoSumIVInputIsBST : public TreeNodeCls {
public:
    static void test() {
        auto root = stringToTreeNode("[2,1,3]");
        auto ret = twoIterator(root, 4);
    }

    static bool twoIteratorStack(TreeNode *root, int k) {
        stack<TreeNode*> stk;
        TreeNode *node = root;
        list<int> desc;
        while (nullptr != node || !stk.empty()) {
            while (nullptr != node) {
                stk.push(node);
                node = node->left;
            }
            // Visit the deepest node
            if (!stk.empty()) {
                TreeNode *t = stk.top();
                stk.pop();
                desc.push_back(t->val);
                node = t->right;
            }
        }
        auto ht = desc.begin();
        auto tt = desc.end(); tt--;

        for (; ht != tt; ) {
            int ret = *ht + *tt;
            if (ret == k) {
                return true;
            } else if (ret > k) {
                --tt;
            } else {
                ++ht;
            }
        }
        return false;
    }

    static bool twoIterator(TreeNode *root, int k) {
        if (nullptr == root) {return false;}
        list<int> desc;
        walk(root, desc);
        auto ht = desc.begin();
        auto tt = desc.end(); tt--;

        for (; ht != tt; ) {
            int ret = *ht + *tt;
            if (ret == k) {
                return true;
            } else if (ret > k) {
                --tt;
            } else {
                ++ht;
            }
        }
        return false;
    }

    static void walk(TreeNode *node, list<int>& desc) {
        if (nullptr == node) {
            return;
        }
        walk(node->left, desc);
        desc.push_back(node->val);
        walk(node->right, desc);
    }

    static bool main(TreeNode *root, int k) {
        if (nullptr == root) {return false;}
        bool find = false;
        unordered_map<int, int> vals;
        walk(root, k, &find, vals);
        return find;
    }

    static void walk(TreeNode *root, int k, bool *find, unordered_map<int, int> &vals) {
        if (nullptr == root) {
            return;
        }
        int rv = k - root->val;
        auto fnd = vals.find(rv);
        if (fnd != vals.end()) {
            *find = true;
            return;
        } else {
            vals.insert(std::make_pair(root->val, 1));
        }
        walk(root->left, k, find, vals);
        walk(root->right, k, find, vals);
    }
};

#endif
