/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int size1 = J.size() , size2 = S.size() , i , count = 0 ;
        map<int , int> mp ;
        for( i = 0 ; i < size2 ; i++ )
        {
            mp[S[i]] += 1 ; 
        }
        for( i = 0 ; i < size1 ; i++ )
        {
            if( mp.find(J[i]) != mp.end() )
                count += mp[J[i]] ;
        }
        return count ;
    }
};
