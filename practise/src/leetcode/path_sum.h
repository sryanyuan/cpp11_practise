#ifndef _INC_PATH_SUM_
#define _INC_PATH_SUM_

class PathSum {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static void test() {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->right = new TreeNode(8);

        TreeNode* child = root->left;
        child->left = new TreeNode(11);

        child = child->left;
        child->left = new TreeNode(7);
        child->right = new TreeNode(2);

        child = root->right;
        child->left = new TreeNode(13);
        child->right = new TreeNode(4);

        child = child->right;
        child->right = new TreeNode(1);

        auto ret = main(root, 55);
    }

    static bool main(TreeNode* root, int sum) {
        if (nullptr == root) {
            return false;
        }

        bool can = false;
        int psum = 0;
        walk(root, sum, psum, &can);
        return can;
    }

    static void walk(TreeNode* node, int sum, int psum, bool* pcan) {
        if (*pcan) {
            return;
        }
        if (nullptr == node) {
            return;
        }

        int csum = psum + node->val;
        if (nullptr == node->left &&
            nullptr == node->right) {
                if (csum == sum) {
                    *pcan = true;
                }
                return;
        }

        walk(node->left, sum, csum, pcan);
        walk(node->right, sum, csum, pcan);
    }
};

#endif
