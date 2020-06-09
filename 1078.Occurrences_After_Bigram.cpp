/*
Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Note:

1 <= text.length <= 1000
text consists of space separated words, where each word consists of lowercase English letters.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.

*/
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        vector<string>v1, res;
        string str = "";
        int i, size = text.size();
        for( i = 0; i < size; i++ )
        {
            if( text[i] == ' ' )
            {
                v1.push_back(str);
                str = "";
            }
            else
            {
                str += text[i]; 
            }
            if( i == size-1 )
            {
                v1.push_back(str);
            }
        }
        
        int size1 = v1.size();
        for( i = 1; i < size1; i++ )
        {
            if( v1[i] == second && v1[i-1] == first && i != size1-1 )
            {
                res.push_back(v1[i+1]);
            }
        }
        return res;
    }
};
