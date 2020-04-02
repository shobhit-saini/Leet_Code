/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
     
        int size = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int i, j, arr[size + 1][size + 1];
        for(i = 0; i <= size; i++)
        {
            for(j = 0; j <= size; j++)
            {
                if(i == 0 || j == 0)
                    arr[i][j] = 0;
                else
                {
                    if(s1[i - 1] == s[j - 1])
                        arr[i][j] = arr[i-1][j-1] + 1;
                    else
                        arr[i][j] = (arr[i-1][j] > arr[i][j-1]) ? arr[i-1][j] : arr[i][j-1];
                }
            }
          
        }
        return arr[size][size];
    }
};
