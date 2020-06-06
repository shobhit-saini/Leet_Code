/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
       
        int size_S = S.size(), i, pos = -size_S;
    
        vector<int>res(size_S);
        for( i = 0; i < size_S; i++ )
        {
            if( S[i] == C )
                pos = i;
            res[i] = i - pos;
        }
        pos = INT_MAX;
        for( i = size_S-1; i >= 0; i-- )
        {
            if( S[i] == C )
                pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
};
