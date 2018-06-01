#ifndef _INC_BALANCED_BINARY_TREE_
#define _INC_BALANCED_BINARY_TREE_

class BalancedBinaryTree {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static void test() {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);

        TreeNode* child = root->right;
        child->left = new TreeNode(15);
        child->right = new TreeNode(7);

        auto ret = main(root);

        // delete not done
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);

        child = root->left;
        child->left = new TreeNode(3);
        child->right = new TreeNode(3);

        child = child->left;
        child->left = new TreeNode(4);
        child->right = new TreeNode(4);

        ret = main(root);
    }

    static bool main(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        int dp = depth(root);
        if (dp < 0) {
            return false;
        }
        return true;
    }

    static int depth(TreeNode* node) {
        if (nullptr == node) {
            return 0;
        }

        int ld = depth(node->left);
        int rd = depth(node->right);
        if (ld < 0 || rd < 0) {
            return -1;
        }

        if (rd > ld) {
            int v = rd;
            rd = ld;
            ld = v;
        }
        if (ld - rd > 1) {
            return -1;
        }
        return ld + 1;
    }
};

#endif
