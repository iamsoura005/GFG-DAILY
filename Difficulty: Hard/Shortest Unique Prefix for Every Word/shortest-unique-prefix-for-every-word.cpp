#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int count;
        
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            count = 0;
        }
    };
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->count++;
        }
    }
    
    string findPrefix(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char ch : word) {
            prefix += ch;
            int index = ch - 'a';
            curr = curr->children[index];
            if (curr->count == 1) {
                return prefix;
            }
        }
        return prefix;
    }

public:
    vector<string> findPrefixes(vector<string>& arr) {
        TrieNode* root = new TrieNode();
        for (const string& word : arr) {
            insert(root, word);
        }
        
        vector<string> result;
        for (const string& word : arr) {
            result.push_back(findPrefix(root, word));
        }
        
        return result;
    }
};