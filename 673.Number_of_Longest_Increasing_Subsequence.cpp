/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& A) {
        
        if(A.size() == 0)
            return 0;
        int size = A.size(), arr[size], max = -1, i, j;
        int count[size], count1 = 0;
        
        for(i = 0; i < size; i++)
        {
            arr[i] = 1;
            count[i] = 1;
        }
        for(i = 1; i < size; i++)
        {
            for(j = 0; j < i; j++)
            {
                if(A[i] > A[j])
                {
                    if(arr[i] < arr[j] + 1)
                        count[i] = count[j];
                    else if(arr[i] == arr[j] + 1)
                        count[i] += count[j];
                    arr[i] = (arr[i] > arr[j] + 1)?arr[i]:arr[j] +1;
                }
            }
        }
        for(i = 0; i < size; i++)
        {
            if(max < arr[i])
                max = arr[i];
        }
        for(i = 0; i < size; i++)
        {
            if(max == arr[i])
                count1 += count[i];
        }
        return count1;
    }
};
