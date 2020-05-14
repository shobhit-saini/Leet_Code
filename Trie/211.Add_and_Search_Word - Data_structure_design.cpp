/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/
class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trie
    {
        map<char, trie*>child;
        bool eow;
    };
    trie* root;    
    WordDictionary() {
        
        root = new trie();
        root->eow = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        
        trie* curr = root;
        for( int i = 0; i < word.size(); i++ )
        {
            if( curr->child.find(word[i]) == curr->child.end() )
            {
                trie* node = new trie();
                node->eow = false;
                curr->child[word[i]] = node;
                curr = node;
            }
            else
            {
                curr = curr->child[word[i]];
            }
        }
        curr->eow = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool fun( string word, trie* curr, int index )
    {
        if( word.size() == index  )
            return curr->eow;
        
        if( word[index] == '.' )
        {
            map<char, trie*>:: iterator itr;
            for( itr = curr->child.begin(); itr != curr->child.end(); itr++ )
            {
                if( fun( word, itr->second, index+1 ) )
                {
                    return true;
                }
            }
        }
        else
        {
            if( curr->child.find(word[index]) == curr->child.end() )
            {
                return false;
            }
            else
            {
                return fun( word, curr->child[word[index]], index+1 );
            }
        }
        return false;
    }
    bool search(string word) {
        
        trie* curr = root;
        return fun( word, curr, 0 );
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
