#ifndef _INC_COMMON_BINARY_TREE_
#define _INC_COMMON_BINARY_TREE_

#include "_common_all.h"
#include <string>
using std::string;
#include <algorithm>
#include <queue>
using std::queue;

class TreeNodeCls {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    static void trimLeftTrailingSpaces(string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    static void trimRightTrailingSpaces(string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    static TreeNodeCls::TreeNode* stringToTreeNode(string input) {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size()) {
            return nullptr;
        }

        string item;
        stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNodeCls::TreeNode* root = new TreeNodeCls::TreeNode(stoi(item));
        queue<TreeNodeCls::TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (true) {
            TreeNodeCls::TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int leftNumber = stoi(item);
                node->left = new TreeNodeCls::TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ',')) {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null") {
                int rightNumber = stoi(item);
                node->right = new TreeNodeCls::TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    static string treeNodeToString(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }

        string output = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                output += "null, ";
                continue;
            }

            output += std::to_string(node->val) + ", ";
            q.push(node->left);
            q.push(node->right);
        }
        return "[" + output.substr(0, output.length() - 2) + "]";
    }
};

#endif
