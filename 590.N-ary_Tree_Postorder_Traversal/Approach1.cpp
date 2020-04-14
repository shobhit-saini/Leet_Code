/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Follow up:

Recursive solution is trivial, could you do it iteratively?

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
*/
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
    vector<int> postorder(Node* root) {
        
       
        stack<Node*> s ;
        int i ;
        Node* value ;
        vector<int> v ;
         if( root == NULL )
            return  v;
        s.push(root);
        while( !s.empty() )
        {
            value = s.top() ;
            
            if( (value -> children).size() == 0)
            {
                v.push_back( value -> val ) ;
            
                s.pop() ;
            }
            else
            {
                for( i = (value -> children).size() - 1 ; i >= 0 ; i-- )
                {
                    s.push( value -> children[i] ) ;
                }
                    (value ->children).clear() ;
            }
        }
        return v;
    }
};
