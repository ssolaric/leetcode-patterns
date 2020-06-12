const int MAX_CHARS = 26;

class Trie {
public:
    Trie() {
        for (int i = 0; i < MAX_CHARS; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(const string& word, int wordIndex) {
        Trie* cur = this;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                cur->children[ind] = new Trie();
            }
            cur = cur->children[ind];
        }
        cur->isEndOfWord = true;
        cur->wordIndex = wordIndex;
    }
    
    bool search(const string& word) {
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
    Trie* children[MAX_CHARS];
    bool isEndOfWord = false;
    int wordIndex = -1;
};

class Solution {
public:
    int indAns = -1;
    int maxSize = 0;
    
    void dfs(Trie* trie, const vector<string>& words) {
        if (trie == nullptr) return;
        if (trie->isEndOfWord) {
            if (trie->wordIndex >= 0 && words[trie->wordIndex].size() > maxSize) {
                indAns = trie->wordIndex;
                maxSize = words[trie->wordIndex].size();
            }
            for (int i = 0; i < MAX_CHARS; i++) {
                Trie* child = trie->children[i];
                dfs(child, words);
            }
        }
    }
    
    string longestWord(vector<string>& words) {               
        Trie* trie = new Trie();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            trie->insert(words[i], i);
        }
        trie->isEndOfWord = true;
        dfs(trie, words);
        if (indAns == -1) {
            return "";
        }
        return words[indAns];
    }
};