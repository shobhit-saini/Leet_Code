/*
Link:https://leetcode.com/problems/detect-capital/
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int size_w = word.size(), i, count = 0;
        for( i = 0; i < size_w; i++ )
        {
            if(isupper(word[i]))
                count++;
        }
        if( count == 0 || count == size_w )
            return true;
        if( count == 1 && isupper(word[0]) )
            return true;
        return false;
    }
};
