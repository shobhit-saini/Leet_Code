class Solution {
public:
    int longestPalindromeSubseq(string s) {
     
        int size = s.size(), arr[size][size], i, j, l;
        for(i = 0; i < size; i++)
        {
            arr[i][i] = 1;
        }
        for(l = 2; l <= size; l++)
        {
            for(i = 0; i < size - l + 1; i++)
            {
                j = l - 1 + i;
                if(s[i] == s[j])
                {
                    if(l == 2)
                        arr[i][j] = 2;
                    else
                        arr[i][j] = arr[i + 1][j-1] + 2;
                }
                else
                    arr[i][j] = (arr[i + 1][j] > arr[i][j - 1]) ? arr[i + 1][j] : arr[i][j-1];
            }
        }
        return arr[0][size - 1];
    }
};
