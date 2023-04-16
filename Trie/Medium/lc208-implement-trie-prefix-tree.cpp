const int MAX_CHARS = 26;

class Trie {
public:
    Trie() {
        for (int i = 0; i < MAX_CHARS; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                cur->children[ind] = new Trie();
            }
            cur = cur->children[ind];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                return false;
            }
            cur = cur->children[ind];
        }
        return cur->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                return false;
            }
            cur = cur->children[ind];
        }
        return true;
    }
private:
    Trie* children[MAX_CHARS];
    bool isEndOfWord = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
