class Solution {
public:
    struct Trie
    {
        map<char, Trie*>child;
        bool eow;
    };
    void Insert( string strs, Trie* root )
    {
        Trie* curr = root;
        for( int i = 0; i < strs.size(); i++ )
        {
            if( curr->child.find( strs[i] ) == curr->child.end() )
            {
                Trie* node = new Trie();
                curr->child[strs[i]] = node;
                node->eow = false;
                curr = node;
            }
            else
            {
                curr = curr->child[strs[i]];
            }
        }
        curr->eow = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie* root = new Trie();
        root->eow = false;
        Trie* tmp = root;
        int i, size = strs.size(), count = 0, min = INT_MAX;
        string res = "";
        for( i = 0; i < size; i++ )
        {
            if( strs[i].size() == 0 )
                return "";
            if( min > strs[i].size() )
                min = strs[i].size();
            Insert(strs[i], root);
        }
        while( tmp->child.size() == 1 && min-- )
        {
            res += tmp->child.begin()->first;
            tmp = tmp->child.begin()->second;
        }
        return res;
    }
};
