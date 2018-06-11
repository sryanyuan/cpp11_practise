#ifndef _INC_FIND_MODE_IN_BINARY_SEARCH_TREE_
#define _INC_FIND_MODE_IN_BINARY_SEARCH_TREE_

#include "_common_binary_tree.h"
#include <unordered_map>
using std::unordered_map;
#include <vector>
using std::vector;

class FindModeInBinarySearchTree : public TreeNodeCls {
public:
    static void test() {
        TreeNode* root = stringToTreeNode("[1,null,2,2]");
        auto ret = main(root);
    }

    static vector<int> main(TreeNode* root) {
        unordered_map<int, int> valCnt;
        walk(root, valCnt);

        vector<int> rets;
        rets.reserve(valCnt.size());
        int mval = 0;

        for (auto & p : valCnt) {
            if (p.second > mval) {
                rets.clear();
                rets.push_back(p.first);
                mval = p.second;
            } else if (p.second == mval) {
                rets.push_back(p.first);
            }
        }
        return rets;
    }

    static void walk(TreeNode* node, unordered_map<int, int>& valCnt) {
        if (nullptr == node) {
            return;
        }
        auto fnd = valCnt.find(node->val);
        if (fnd == valCnt.end()) {
            valCnt.insert(std::make_pair(node->val, 1));
        } else {
            fnd->second++;
        }
        walk(node->left, valCnt);
        walk(node->right, valCnt);
    }
};

#endif
