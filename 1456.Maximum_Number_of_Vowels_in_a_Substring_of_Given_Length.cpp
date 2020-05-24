/*
Given a string s and an integer k.

Return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are (a, e, i, o, u).

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
Example 4:

Input: s = "rhythms", k = 4
Output: 0
Explanation: We can see that s doesn't have any vowel letters.
Example 5:

Input: s = "tryhard", k = 4
Output: 1
 

Constraints:

1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        
        int i, size = s.size(), max_count = 0, j, count = 0;
        string str = "";
        for( i = 0; i < k; i++ )
        {
            if( s[i] == 'a' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'e' )
            {
                count++;
            }
            str += s[i];
        }
        if( max_count < count )
            max_count = count;
        for( j = i; j < size; j++ )
        {
            if( str[0] == 'a' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'e' )
            {
                count--;
            }
            str.erase(0,1);
            if( s[j] == 'a' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'e' )
            {
                count++;
            }
            if( max_count < count )
            {
                max_count = count;
                if( max_count == k )
                    return k;
            }
            str += s[j];
        }
        return max_count;
    }
};
