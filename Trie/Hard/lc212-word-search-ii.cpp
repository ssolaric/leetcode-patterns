const int MAX_CHARS = 26;

class Trie {
public:
    Trie() {
        for (int i = 0; i < MAX_CHARS; i++) {
            children[i] = nullptr;
        }
    }

    void insert(const string& word, int wordInd) {
        Trie* cur = this;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                cur->children[ind] = new Trie();
            }
            cur = cur->children[ind];
        }
        cur->isEndOfWord = true;
        cur->wordInd = wordInd;
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

    bool startsWith(const string& word) {
        Trie* cur = this;
        for (char c : word) {
            int ind = c - 'a';
            if (cur->children[ind] == nullptr) {
                return false;
            }
            cur = cur->children[ind];
        }
        return true;
    }

    Trie* children[MAX_CHARS];
    bool isEndOfWord = false;
    int wordInd = -1;
};

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    int n, m;

    void backtrack(int row, int col, vector<vector<char>>& board, vector<string>& words, Trie* cur,
                   vector<string>& ans) {
        if (cur == nullptr) {
            return;
        }
        if (cur->isEndOfWord) {
            ans.push_back(words[cur->wordInd]);
            cur->isEndOfWord = false;
        }
        if (row < 0 || col < 0 || row >= n || col >= m) return;
        char boardLetter = board[row][col];
        if (board[row][col] == '-') return;
        board[row][col] = '-';
        for (int d = 0; d < 4; d++) {
            int nrow = row + dr[d];
            int ncol = col + dc[d];
            backtrack(nrow, ncol, board, words, cur->children[boardLetter - 'a'], ans);
        }
        board[row][col] = boardLetter;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        Trie* dictionary = new Trie();
        for (int i = 0; i < words.size(); i++) {
            dictionary->insert(words[i], i);
        }
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backtrack(i, j, board, words, dictionary, ans);
            }
        }
        return ans;
    }
};
