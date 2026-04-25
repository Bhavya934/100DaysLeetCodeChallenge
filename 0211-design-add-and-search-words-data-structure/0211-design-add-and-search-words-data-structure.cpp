class WordDictionary {
public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEndOfWord = false;
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

private:
    bool searchInNode(const string& word, int index, TrieNode* node) {
        if (!node) return false;
        if (index == word.length()) return node->isEndOfWord;

        char c = word[index];
        if (c != '.') {
            return searchInNode(word, index + 1, node->children[c - 'a']);
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    if (searchInNode(word, index + 1, node->children[i])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */