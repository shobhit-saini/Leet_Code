class Solution {
public:
    int fun(string text1, string text2, int *arr, int i, int j)
    {
        if(i == 0 || j == 0)
            return 0;
        if(*((arr+i*text2.size()) + j) != -1)
        {
            return *((arr+i*text2.size()) + j);
        }
        if(text1[i-1] == text2[j-1])
        {
            *((arr+i*text2.size()) + j) = 1 + fun(text1, text2, arr, i - 1, j - 1);
            return *((arr+i*text2.size()) + j);
        }
        else
        {
            *((arr+i*text2.size()) + j) = max(fun(text1, text2, arr, i - 1, j), fun(text1, text2, arr, i, j - 1));
            return *((arr+i*text2.size()) + j);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int arr[text1.size()+1][text2.size()+1],i,j;
        for(i = 0; i < text1.size()+1; i++)
        {
            for(j = 0; j < text2.size()+1; j++)
            {
                arr[i][j] = -1;
            }
        }
        return fun(text1, text2, (int*)arr, text1.size(), text2.size());
        
    }
};
