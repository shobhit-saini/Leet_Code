/*
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.

 

Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]
 

Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        int size = A.size(), j, i, k; 
        vector<string>res;
        int arr1[26], arr2[26];
        for( i = 0; i < 26; i++ )
        {
            arr1[i] = INT_MAX;
            arr2[i] = 0;
        }
        for( i = 0; i < size; i++ )
        {
            int arr2[26] = {0};
            for( j = 0; j < A[i].size(); j++ )
            {
                arr2[A[i][j]-'a']++;
            }

            for( k = 0; k < 26; k++ )
            {
                arr1[k] = min( arr1[k], arr2[k] );
                arr2[k] = 0;
            }

        }

        for( i = 0; i < 26; i++ )
        {
            for( j = 0; j < arr1[i]; j++ )
            {
                res.push_back(string(1,i + 'a'));
            }
        }
        return res;
    }
};
