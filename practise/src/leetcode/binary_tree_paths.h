#ifndef _INC_BINARY_TREE_PATHS_
#define _INC_BINARY_TREE_PATHS_

#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;
#include <stdlib.h>

class BinaryTreePaths {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    static vector<string> main(TreeNode *root) {
        if (nullptr == root) {
            return vector<string>();
        }
        vector<string> rets;
        string pstr;
        appendInt(pstr, root->val);
        walk(root, pstr, rets);
        return rets;
    }

    static void walk(TreeNode *node, const string& pstr, vector<string>& rets) {
        // Left node
        if (nullptr == node->left && nullptr == node->right) {
            rets.push_back(pstr);
            return;
        }
        // Check left child
        if (nullptr != node->left) {
            string nstr = pstr + "->";
            appendInt(nstr, node->left->val);
            walk(node->left, nstr, rets);
        }
        // Check right child
        if (nullptr != node->right) {
            string nstr = pstr + "->";
            appendInt(nstr, node->right->val);
            walk(node->right, nstr, rets);
        }
    }

    static void appendInt(string& str, int n) {
        str += to_string(n);
    }
};

#endif
