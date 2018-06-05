#ifndef _INC_INVERT_BINARY_TREE_
#define _INC_INVERT_BINARY_TREE_

class InvertBinaryTree {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static TreeNode* main(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        walkAndChange(root);
        return root;
    }

    static void walkAndChange(TreeNode* node) {
        if (nullptr == node) {
            return;
        }
        TreeNode* n = node->right;
        node->right = node->left;
        node->left = n;
        walkAndChange(node->left);
        walkAndChange(node->right);
    }
};

#endif
