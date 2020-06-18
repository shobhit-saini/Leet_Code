/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        
        map<string, int>mp;
        string str = "";
        int i, size_A = A.size(), size_B = B.size();
        vector<string>res;
        for( i = 0; i < size_A; i++ )
        {
            if( i == size_A-1 )
            {
                str += A[i];
                mp[str]++;
                break;
            }
            if( A[i] == ' ' )
            {
                mp[str]++;
                str = "";
            }
            else
            {
                str += A[i];
            }
        }
        
        str = "";
        for( i = 0; i < size_B; i++ )
        {
            if( i == size_B-1 )
            {
                str += B[i];
                mp[str]++;
                break;
            }
            if( B[i] == ' ' )
            {
                mp[str]++;
                str = "";
            }
            else
            {
                str += B[i];
            }
        }
        map<string, int>:: iterator itr;
        
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            if( itr->second == 1 )
                res.push_back(itr->first);
        }
        return res;
    }
};
