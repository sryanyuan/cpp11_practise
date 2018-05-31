#ifndef _INC_SAME_TREE_
#define _INC_SAME_TREE_

class SameTree {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static bool main(TreeNode* p, TreeNode* q) {
        if ((nullptr == p || nullptr == q) && p != q) {
            return false;
        }
        if (nullptr == p) {
            return true;
        }

        return walk(p, q);
    }

    static bool walk(TreeNode* p, TreeNode* q) {
        if ((nullptr == p || nullptr == q) && p != q) {
            return false;
        }
    }
};

#endif
