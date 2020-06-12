const int MAX_CHARS = 26;

class Trie {
public:
    Trie() {
        for (int i = 0; i < MAX_CHARS; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(const string& word) {
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
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            trie->insert(words[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < text.size(); i++) {
            // If a substring starting at i has a prefix in words:
            // Find all substrings starting at i that have a prefix in "words".
            Trie* cur = trie;
            for (int j = i; j < text.size(); j++) {
                int trieInd = text[j] - 'a';
                if (cur->children[trieInd] == nullptr) {
                    break;
                }
                cur = cur->children[trieInd];
                if (cur->isEndOfWord) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};