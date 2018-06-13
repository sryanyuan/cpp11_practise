#ifndef _INC_AVERAGE_OF_LEVELS_IN_BINARY_TREE_
#define _INC_AVERAGE_OF_LEVELS_IN_BINARY_TREE_

#include "_common_binary_tree.h"

class AverageOfLevelsInBinaryTree : public TreeNodeCls {
public:
    static void test() {

    }

    static vector<double> main(TreeNode *root) {
        if (nullptr == root) {
            return vector<double>();
        }
        vector<double> rets;
        list<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            list<TreeNode*> curnodes;
            long long sum = 0;
            int cnt = 0;
            for (auto t : nodes) {
                sum += (long long)t->val;
                ++cnt;
                if (nullptr != t->left) {
                    curnodes.push_back(t->left);
                }
                if (nullptr != t->right) {
                    curnodes.push_back(t->right);
                }
            }
            rets.push_back(double(sum) / double(cnt));
            nodes = move(curnodes);
        }
        return rets;
    }
};

#endif
