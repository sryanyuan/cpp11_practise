#ifndef _INC_ADD_AND_SEARCH_WORD_DATA_STRUCTURE_DESIGN_
#define _INC_ADD_AND_SEARCH_WORD_DATA_STRUCTURE_DESIGN_

/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include "_common_all.h"

class AddAndSearchWordDataStructureDesign {
public:
    static void test() {
        WordDictionary *obj = new WordDictionary();
        obj->addWord("bad");
        obj->addWord("dad");
        obj->addWord("mad");
        obj->search("pad"); //-> false
        obj->search("bad"); //-> true
        obj->search(".ad"); //-> true
        obj->search("b.."); //-> true
    }

    class WordDictionary {
    public:
        struct TNode {
            bool wend_;
            unordered_map<char, TNode*> *next_;
            TNode() {
                wend_ = false;
                next_ = nullptr;
            }
        };
        /** Initialize your data structure here. */
        WordDictionary() {
            root_ = nullptr;
        }

        /** Adds a word into the data structure. */
        void addWord(string word) {
            if (word.empty()) {
                return;
            }
            if (nullptr == root_) {
                root_ = new TNode;
            }
            TNode *node = root_;
            for (auto v : word) {
                if (nullptr == node->next_) {
                    node->next_ = new unordered_map<char, TNode*>;
                }
                TNode *next = nullptr;
                auto fnd = node->next_->find(v);
                if (fnd == node->next_->end()) {
                    next = new TNode;
                    node->next_->insert(std::make_pair(v, next));
                } else {
                    next = fnd->second;
                }
                node = next;
            }
            node->wend_ = true;
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            return searchNode(root_, word);
        }

        bool searchNode(TNode *node, string &word) {
            if (nullptr == node) {
                return false;
            }
            if (word.empty() && node->wend_) {
                return true;
            }
            for (int i = 0; i < word.size(); i++) {
                if (nullptr == node->next_) {
                    return false;
                }
                if (word[i] == '.') {
                    string sub = word.substr(i + 1, word.size() - 1 - (i + 1) + 1);
                    for (auto &pa : *node->next_) {
                        if (searchNode(pa.second, sub)) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    auto fnd = node->next_->find(word[i]);
                    if (fnd == node->next_->end()) {
                        return false;
                    }
                    node = fnd->second;
                }
            }
            return node->wend_;
        }

        TNode *root_;
    };

    /**
    * Your WordDictionary object will be instantiated and called as such:
    * WordDictionary obj = new WordDictionary();
    * obj.addWord(word);
    * bool param_2 = obj.search(word);
    */
};

#endif
