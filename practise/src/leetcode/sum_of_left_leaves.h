#ifndef _INC_SUM_OF_LEFT_LEAVES_
#define _INC_SUM_OF_LEFT_LEAVES_

class SumOfLeftLeaves {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static int main(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int sum = 0;
        walk(root, sum, false);
        return sum;
    }

    static void walk(TreeNode* node, int& sum, bool left) {
        if (node->left == nullptr && node->right == nullptr && left) {
            sum += node->val;
            return;
        }
        if (nullptr != node->left) {
            walk(node->left, sum, true);
        }
        if (nullptr != node->right) {
            walk(node->right, sum, false);
        }
    }
};

#endif
