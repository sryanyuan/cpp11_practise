#ifndef _INC_SAME_TREE_
#define _INC_SAME_TREE_

/*
https://leetcode.com/problems/same-tree/description/

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
/ \       / \
2   3     2   3

[1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
/           \
2             2

[1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
/ \       / \
2   1     1   2

[1,2,1],   [1,1,2]

Output: false
*/

#include <stack>
using std::stack;

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

        stack<TreeNode*> pNodes;
        stack<TreeNode*> qNodes;
        pNodes.push(p);
        qNodes.push(q);

        while (!pNodes.empty() && !qNodes.empty()) {
            TreeNode* pnode = pNodes.top();
            pNodes.pop();

            TreeNode* qnode = qNodes.top();
            qNodes.pop();

            // Visit the node
            if (pnode->val != qnode->val) {
                return false;
            }

            // Push right and left node
            if (nullptr != pnode->right) {
                if (nullptr == qnode->right) {
                    return false;
                }
                pNodes.push(pnode->right);
                qNodes.push(qnode->right);
            } else if (nullptr != qnode->right) {
                return false;
            }
            if (nullptr != pnode->left) {
                if (nullptr == qnode->left) {
                    return false;
                }
                pNodes.push(pnode->left);
                qNodes.push(qnode->left);
            } else if (nullptr != qnode->left) {
                return false;
            }
        }

        if (pNodes.size() != qNodes.size()) {
            return false;
        }
        return true;
    }
};

#endif
