#ifndef _INC_IMPLEMENT_TRIE_PREFIX_TREE_
#define _INC_IMPLEMENT_TRIE_PREFIX_TREE_

#include "_common_all.h"

/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class ImplementTriePrefixTree {
public:
    static void test() {
        Trie *trie = new Trie();

        trie->insert("app");
        trie->insert("apple");
        trie->insert("beer");
        trie->insert("add");
        trie->insert("jam");
        trie->insert("rental");
        bool res = trie->search("apps");   // returns true
        res = trie->search("app");     // returns false
        res = trie->startsWith("app"); // returns true
        trie->insert("app");   
        res = trie->search("app");     // returns true
    }

    class Trie {
    public:
        struct TNode {
            bool wend;
            unordered_map<char, TNode*> *next_;

            TNode() {
                wend = false;
                next_ = nullptr;
            }
        };
        /** Initialize your data structure here. */
        Trie() {
            root_ = nullptr;
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            if (word.empty()) {
                return;
            }
            if (nullptr == root_) {
                root_ = new unordered_map<char, TNode*>;
            }
            unordered_map<char, TNode*>* curm = root_;
            for (int i = 0; i < word.size(); i++) {
                auto fnd = curm->find(word[i]);
                TNode *cur = nullptr;
                if (fnd == curm->end()) {
                    cur = new TNode;
                    curm->insert(std::make_pair(word[i], cur));
                } else {
                    cur = fnd->second;
                }
                if (i == word.size() - 1) {
                    cur->wend = true;
                } else {
                    if (nullptr == cur->next_) {
                        cur->next_ = new unordered_map<char, TNode*>;
                    }
                    curm = cur->next_;
                }
            }
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TNode *cur = findw(word);
            if (nullptr == cur) {
                return false;
            }
            return cur->wend;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            return nullptr != findw(prefix);
        }

        TNode *findw(string &word) {
            TNode *node = nullptr;
            unordered_map<char, TNode*> *curm = root_;
            for (int i = 0; i < word.size() && nullptr != curm; i++) {
                auto fnd = curm->find(word[i]);
                if (fnd == curm->end()) {
                    break;
                }
                TNode *cur = fnd->second;
                if (i == word.size() - 1) {
                    node = cur;
                } else {
                    curm = cur->next_;
                }
            }
            return node;
        }

        unordered_map<char, TNode*> *root_;
    };
};

#endif
