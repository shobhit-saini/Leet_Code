/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        map<int, int>mp;
        int i, size = text.size(), str_size = 7, count = 0;
        string str = "balloon";
        for( i = 0; i < size; i++ )
        {
            mp[text[i]]++;
        }
        while(1)
        {
            for( i = 0; i < str.size(); i++ )
            {
                if( mp.find(str[i]) != mp.end() && mp[str[i]] > 0 )
                    mp[str[i]]--;
                else
                    break;
            }
            if( i == str_size )
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
    
};
