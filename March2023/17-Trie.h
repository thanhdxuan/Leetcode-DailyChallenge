#include <string>
using namespace std;

class Trie {
public:
  class TrieNode;
private:
  TrieNode *root;
public:
    Trie() {
      root = new TrieNode;
    }
    
    void insert(string word) {
      TrieNode *walker = this->root;
      for (int i = 0; i < (int)word.length(); i++) {
        int key = word[i] - 'a';
        if (walker->child[key] == nullptr) {
          walker->child[key] = new TrieNode();
        }
        walker = walker->child[key];
      }
      walker->endofwords = true;
    }
    
    bool search(string word) {
      TrieNode *walker = root;
      int n = word.length();
      for(int i = 0; i < (int)word.length(); i++) {
        int key = word[i] - 'a';
        if (!walker->child[key]) return false;
        walker = walker->child[key];
        if (i == n - 1) { if (walker->endofwords == false) return false; }
      }
      return true;
    }
    
    bool startsWith(string prefix) {
      TrieNode *walker = root;
      for(int i = 0; i < (int)prefix.length(); i++) {
        int key = prefix[i] - 'a';
        if (walker->child[key] == nullptr) return false;
        walker = walker->child[key];
      }
      return true;
    }
    
    class TrieNode {
    public:
        TrieNode **child;
        bool endofwords;
    public:
        TrieNode() {
            child = new TrieNode*[26];
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            endofwords = false;
        }
    };
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
