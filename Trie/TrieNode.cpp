#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode('\0')) {}

    void insertUtil(TrieNode* node, const string& word) {
        // base case
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        // assumption word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            // absent
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(const string& word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* node, const string& word) {
        // base case
        if (word.length() == 0) {
            return node->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // present
        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            // absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(const string& word) {
        return searchUtil(root, word);
    }

    // Destructor to free the allocated memory
    ~Trie() {
        delete root;
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("abcd");
    t->insertWord("Time");
    t->insertWord("Check");
    cout << "Present or Not = " << t->searchWord("Time");

    delete t;  // Don't forget to release the allocated memory

    return 0;
}
