//Problem: Chapter 6. Store & Search String
#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    //set all children to nullptr
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    void insertFirst(const string& key) {
        TrieNode* current = root;
        for (char c : key) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        if (current->isEndOfWord) {
            // Key already exists
        } else {
            current->isEndOfWord = true;
        }
    }
    void insert(const string& key) {
        TrieNode* current = root;
        for (char c : key) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        if (current->isEndOfWord) {
            cout << "0\n";  // Key already exists
        } else {
            current->isEndOfWord = true;
            cout << "1\n";  // Successful insertion
        }
    }

    bool find(const string& key) {
        TrieNode* current = root;
        for (char c : key) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;  // Key not found
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
};

int main() {
    freopen("test1.txt","r",stdin);
    vector<string> keys;

    // Read the first block of information
    string key;
    while (cin >> key && key != "*") {
        keys.push_back(key);
    }

    Trie trie;

    // Build the trie using the keys from the database
    for (const string& key : keys) {
        trie.insertFirst(key);
    }

    // Read the second block of information
    string cmd, k;
    while (cin >> cmd >> k && cmd != "***") {
        if (cmd == "find") {
            cout << trie.find(k) << '\n';
        } else if (cmd == "insert") {
            trie.insert(k);
        }
    }

    return 0;
}