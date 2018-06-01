#ifndef _INC_MINIMUM_DEPTH_OF_BINARY_TREE_
#define _INC_MINIMUM_DEPTH_OF_BINARY_TREE_

class MinimumDepthOfBinaryTree {
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
    }

    static int main(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int nMin = 2147483647;
        int dp = 1;
        walk(root, dp, &nMin);

        return nMin;
    }

    static void walk(TreeNode* node, int pd, int* pmin) {
        if (nullptr == node) {
            return;
        }
        if (nullptr == node->left && nullptr == node->right) {
            // node is leaf node
            if (pd < *pmin) {
                *pmin = pd;
                return;
            }
        }
        if (pd >= *pmin) {
            return;
        }

        int cd = pd + 1;
        walk(node->left, cd, pmin);
        walk(node->right, cd, pmin);
    }
};

#endif
