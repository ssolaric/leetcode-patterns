const int MAX_CHARS = 26;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < MAX_CHARS; i++) {
            children[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (cur->children[ind] == nullptr) {
                cur->children[ind] = new Trie();
            }
            cur = cur->children[ind];
        }
        cur->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (cur->children[ind] == nullptr) {
                return false;
            }
            cur = cur->children[ind];
        }
        return cur->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (int i = 0; i < prefix.size(); i++) {
            int ind = prefix[i] - 'a';
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