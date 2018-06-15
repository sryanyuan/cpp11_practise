#ifndef _SECOND_MINIMUM_NODE_IN_A_BINARY_TREE_
#define _SECOND_MINIMUM_NODE_IN_A_BINARY_TREE_

#include "_common_binary_tree.h"

class SecondMinimumNodeInABinaryTree : public TreeNodeCls {
public:
    static void test() {
        auto root = stringToTreeNode("[1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1]");
        auto ret = main(root);
    }

    static int main(TreeNode *root) {
        int mmin = root->val;
        vector<TreeNode*> lnodes(1);
        lnodes[0] = root;
        while (!lnodes.empty()) {
            vector<TreeNode*> cnodes;
            int *cmin = nullptr;
            for (auto n : lnodes) {
                if ((n->val < mmin && mmin != root->val && n->val != root->val) || 
                    (n->val > mmin && mmin == root->val)) {
                    if (nullptr == cmin) {
                        cmin = new int;
                        *cmin = n->val;
                    } else if (n->val < *cmin) {
                        *cmin = n->val;
                    }
                }
            }
            if (nullptr != cmin) {
                if (mmin == root->val || *cmin < mmin) {
                    mmin = *cmin;
                }
                delete cmin;
                cmin = nullptr;
            }
            for (auto n : lnodes) {
                if ((n->val <= mmin && mmin == root->val) || 
                    (mmin != root->val && n->val < mmin - 1)) {
                    if (nullptr != n->left) {
                        cnodes.push_back(n->left);
                    }
                    if (nullptr != n->right) {
                        cnodes.push_back(n->right);
                    }
                }
            }
            lnodes = std::move(cnodes);
        }

        if (mmin == root->val) {
            return -1;
        }
        return mmin;
    }
};

#endif
