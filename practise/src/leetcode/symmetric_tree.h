#ifndef _INC_SYMMETRIC_TREE_
#define _INC_SYMMETRIC_TREE_

#include <stack>
using std::stack;

class SymmetricTree {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static bool main(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        TreeNode* p = root->left;
        TreeNode* q = root->right;

        if ((nullptr == p || nullptr == q) && p != q) {
            return false;
        }
        if (nullptr == p) {
            return true;
        }

        stack<TreeNode*> pNodes;
        pNodes.push(p);
        stack<TreeNode*> qNodes;
        qNodes.push(q);

        while (!pNodes.empty() && !qNodes.empty()) {
            TreeNode* pnode = pNodes.top();
            pNodes.pop();

            TreeNode* qnode = qNodes.top();
            qNodes.pop();

            if (pnode->val != qnode->val) {
                return false;
            }

            if (nullptr != pnode->right) {
                if (nullptr == qnode->left) {
                    return false;
                }
                pNodes.push(pnode->right);
                qNodes.push(qnode->left);
            } else if (nullptr != qnode->left) {
                return false;
            }
            if (nullptr != pnode->left) {
                if (nullptr == qnode->right) {
                    return false;
                }
                pNodes.push(pnode->left);
                qNodes.push(qnode->right);
            } else if (nullptr != qnode->right) {
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
