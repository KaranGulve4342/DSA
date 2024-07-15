// LEETCODE 208

#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(int i = 0;i < word.length();i++){
            if(curr->containsKey(word[i]) == NULL){
                curr->put(word[i], new Node());
            }
            curr = curr->get(word[i]);
        }

        curr->setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i = 0;i < word.length();i++){
            if(curr->containsKey(word[i]) == NULL){
                return false;
            }
            curr = curr->get(word[i]);
        }

        return curr->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0;i < prefix.length();i++){
            if(curr->containsKey(prefix[i]) == NULL){
                return false;
            }
            curr = curr->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */