
#include<bits/stdc+++.h>
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

        int index = word[0] - 'a';
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

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a';ch <= 'z';ch++){
            TrieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }


    vector<vector<string> >getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string> >output;
        strig prefix = "";

        for(int i = 0;i < str.length();i++){
            char lastch = str[i];

            prefix.push_back(lastch);

            TrieNode* curr = prev->children[lastch - 'a'];

            // if not found
            if(curr == NULL){
                break;
            }

            // if fount
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }

        return output;
    }



    // Destructor to free the allocated memory
    ~Trie() {
        delete root;
    }
};

vector<vector<string> > phoneDirectory(vector<string> contactList, string &queryStr){
    Trie *t = new Trie();

    for(int i = 0;i < contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}