/*
Given an array A of non-negative integers, return the maximum sum of elements in two non-overlapping (contiguous) subarrays, which have lengths L and M.  (For clarification, the L-length subarray could occur before or after the M-length subarray.)

Formally, return the largest V for which V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) and either:

0 <= i < i + L - 1 < j < j + M - 1 < A.length, or
0 <= j < j + M - 1 < i < i + L - 1 < A.length.
 

Example 1:

Input: A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
Example 2:

Input: A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
Example 3:

Input: A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [3,8] with length 3.
 

Note:

L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000
*/
class Solution {
public:
    int sum( vector<int>A, int L, int M )
    {
        int res = 0, lmax = 0;
        for( int i = L+M; i < A.size(); i++ )
        {
            lmax = max(lmax, A[i-M] - A[i-L-M]);
            res = max( res, lmax + A[i] - A[i-M] );
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
     
        int i, size = A.size();
        vector<int> prefix_sum(size+1);
        prefix_sum[0] = 0;
        for( i = 0; i < size; i++ )
        {
            prefix_sum[i+1] = prefix_sum[i] + A[i]; 
        }
        return max( sum( prefix_sum, L, M ), sum( prefix_sum, M, L ) );
    }
};
