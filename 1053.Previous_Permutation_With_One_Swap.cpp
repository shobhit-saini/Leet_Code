/*
Given an array A of positive integers (not necessarily distinct), return the lexicographically largest permutation that is smaller than A, that can be made with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).  If it cannot be done, then return the same array.

 

Example 1:

Input: [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
Example 3:

Input: [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
Example 4:

Input: [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.
*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        
        int i, size = A.size(), j, index, flag = 0;
        for( i = size-2; i >= 0; i-- )
        {
            if( A[i] > A[i+1] )
            {
                break;
            }
        }
        if( i == -1 )
            return A;
        
        for( j = size-1; j > i ; j-- )
        {
            if( A[j] < A[i] && flag == 0 )
            {
                flag = 1;
                index = j;
            }
            if( flag == 1 )
            {
                if( A[index] == A[j] )
                {
                    index = j;
                }
            }
        }
        int temp = A[index];
        A[index] = A[i];
        A[i] = temp;
        return A;
    }
};
