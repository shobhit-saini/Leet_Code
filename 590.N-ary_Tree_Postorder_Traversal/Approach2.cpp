/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>Postorder( Node* root , vector<int> &v )
    {
        if( root != NULL )
        {
            for( int i = 0 ; i < (root -> children).size() ; i++ )
                Postorder( root -> children[i] , v );
            v.push_back( root -> val ) ;
        
        }
        return v ;
    }
    vector<int> postorder(Node* root) {
        vector<int> v ;
        return Postorder( root , v ) ;      
    }
};
