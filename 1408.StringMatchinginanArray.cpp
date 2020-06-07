/*
Given an array of string words. Return all strings in words which is substring of another word in any order. 

String words[i] is substring of words[j], if can be obtained removing some characters to left and/or right side of words[j].

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
It's guaranteed that words[i] will be unique.
*/
class Solution {
public:
    static bool comp( string s1, string s2 )
    {
        return s1.size() < s2.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        
        int i, size = words.size(), j;
        vector<string>res;
        sort( words.begin(), words.end(), comp );
        for( i = 0; i < size; i++ )
        {
            for( j = i+1; j < size; j++ )
            {
                if( words[j].find(words[i]) != -1 )
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
