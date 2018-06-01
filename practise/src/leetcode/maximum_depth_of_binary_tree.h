#ifndef _INC_MAXIMUM_DEPTH_OF_BINARY_TREE_
#define _INC_MAXIMUM_DEPTH_OF_BINARY_TREE_

/* TODO to slow (using stack ?)
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
*/

class MaximumDepthOfBinaryTree {
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

        int depth = 0;
        int ret = 0;
        walk(root, depth, &ret);
        return ret;
    }

    static void walk(TreeNode* root, int depth, int* pmaxdepth) {
        int curdepth = depth + 1;
        if (*pmaxdepth < curdepth) {
            *pmaxdepth = curdepth;
        }
        if (nullptr != root->left) {
            walk(root->left, curdepth, pmaxdepth);
        }
        if (nullptr != root->right) {
            walk(root->right, curdepth, pmaxdepth);
        }
    }
};

#endif
