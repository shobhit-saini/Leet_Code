/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char, int>mp1, mp2;
        vector<int>res;
        int i, size1 = s.size(), size2 = p.size(), count = 0, j, k;
        for( i = 0; i < size2; i++ )
        {
            mp1[p[i]] += 1; 
        }
        j = 0;
        for( i = 0; i < size2; i++ )
        {
            mp2[s[i]] += 1;
        }
        map<char, int>::iterator itr1, itr2;
        for( itr1 = mp1.begin(), itr2 = mp2.begin(); itr1 != mp1.end(), itr2 != mp2.end(); itr1++, itr2++ )
        {
            if( (itr1 -> first == itr2 -> first && itr1->second != itr2->second) || (itr1->first != itr2->first) )
                break;
            count = count+itr1->second;
        }
        if( count == size2 )
            res.push_back( i-size2 );
        for( k = i; k < size1; k++ )
        {
            if( mp2[s[j]] == 1 )
                mp2.erase(s[j]);
            else
                mp2[s[j]]--;
            mp2[s[k]] += 1;
            count = 0;
            map<char, int>::iterator itr1, itr2;
            for( itr1 = mp1.begin(), itr2 = mp2.begin(); itr1 != mp1.end(), itr2 != mp2.end(); itr1++, itr2++ )
            {
                if( (itr1 -> first == itr2 -> first && itr1->second != itr2->second) || (itr1->first != itr2->first) )
                    break;
                count += itr1->second;
            }
            if( count == size2 )
                res.push_back( k-size2+1 );
                j++;
            }
        return res;
    }
};
