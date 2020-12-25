class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        bool endofword;
        map<char, TrieNode*> children; 
        TrieNode()
        {
            endofword = false;
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); ++i)
        {
            if(curr->children.find(word[i]) == curr->children.end())
            {
                curr->children[word[i]] = new TrieNode();
                curr = curr->children[word[i]];
            }
            else
                curr = curr->children[word[i]];
        }
        curr->endofword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int i=0;
        while(i<word.length())
        {
            if(curr->children.find(word[i]) == curr->children.end())
                return false;
            curr = curr->children[word[i]];
            i++;
        }
        return curr->endofword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int i=0;
        while(i<prefix.length())
        {
            if(curr->children.find(prefix[i]) == curr->children.end())
                return false;
            curr = curr->children[prefix[i]];
            ++i;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
