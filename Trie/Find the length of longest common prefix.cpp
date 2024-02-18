// LEETCODE 3043

class TrieNode {
public:
    TrieNode() : isEnd(false) {
        children.resize(10, nullptr);
    }
    
    vector<TrieNode*> children;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int number) {
        TrieNode* current = root;
        string str_number = to_string(number);
        for (char c : str_number) {
            int digit = c - '0';
            if (current->children[digit] == nullptr) {
                current->children[digit] = new TrieNode();
            }
            current = current->children[digit];
        }
        current->isEnd = true;
    }
    
    int longestCommonPrefixLength(int number) {
        TrieNode* current = root;
        string str_number = to_string(number);
        int len_number = 0;
        for (char c : str_number) {
            int digit = c - '0';
            if (current->children[digit] == nullptr) {
                return len_number;
            }
            current = current->children[digit];
            len_number++;
        }
        return len_number;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        int max_length = 0;
        for (int number : arr1) {
            trie.insert(number);
        }
        for (int number : arr2) {
            max_length = max(max_length, trie.longestCommonPrefixLength(number));
        }
        return max_length;
    }
};