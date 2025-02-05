class trie {
public:
    bool isEnd;
    trie* child[26];
    trie() {
        isEnd = false;
        for (int i=0; i<26; i++) child[i] = nullptr;
    }
};

class WordDictionary {
public:
    trie* root;
    WordDictionary() {
        root = new trie();
    }
    
    void addWord(string word) {
        trie* node = root;
        for (auto x : word) {
            int index = x - 'a';
            if (!node->child[index]) node->child[index] = new trie();
            node = node->child[index];
        }
        node->isEnd = true;
    }

    bool searchTrie(trie* curr, string& word, int currIndex) {
        if (currIndex == word.size()) return curr->isEnd;

        if (word[currIndex] != '.') {
            int charIndex = word[currIndex] - 'a';
            if (curr->child[charIndex]) curr = curr->child[charIndex];
            else return false;
            return searchTrie(curr, word, currIndex + 1);
        }
        else {
            for (int i=0; i<26; i++) {
                if (curr->child[i] && searchTrie(curr->child[i], word, currIndex + 1)) return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        trie* curr = root;
        return searchTrie(curr, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
