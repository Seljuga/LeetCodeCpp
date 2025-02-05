class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
    TrieNode() : word("") {}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insertWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word;
    }
};

class Solution {
private:
    void backtrack(vector<vector<char>>& board, int row, int col, TrieNode* node, unordered_set<string>& ans) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#') return;
        char letter = board[row][col];
        TrieNode* currNode = node->children[letter];
        if (!currNode) return;

        if(!currNode->word.empty()) {
            ans.insert(currNode->word);
            currNode->word = "";
        }
        board[row][col] = '#';

        backtrack(board, row + 1, col, currNode, ans);
        backtrack(board, row - 1, col, currNode, ans);
        backtrack(board, row, col + 1, currNode, ans);
        backtrack(board, row, col - 1, currNode, ans);

        board[row][col] = letter;
        if (currNode->children.empty()) node->children.erase(letter);
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words) trie.insertWord(word);
        unordered_set<string> ans;
        int rows = board.size(), cols = board[0].size();
        for (int r=0; r<rows; r++) {
            for (int c=0; c<cols; c++) {
                backtrack(board, r, c, trie.root, ans);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
