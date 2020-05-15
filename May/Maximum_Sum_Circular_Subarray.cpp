/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
 
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int sum = 0, size = A.size(), i, max_so_far = INT_MIN, min_so_far = INT_MAX, sum1 = 0, sum2 = 0, Tsum = 0;
        for( i = 0; i < size; i++ )
        {
            sum1 += A[i];
            sum2 += A[i];
            Tsum += A[i];
            if( max_so_far < sum1 )
                max_so_far = sum1;
            if( sum1 < 0 )
                sum1 = 0;
            if( min_so_far > sum2 )
                min_so_far = sum2;
            if( sum2 > 0 )
                sum2 = 0;
        }
        return max_so_far > 0 ? max( max_so_far, Tsum-min_so_far ): max_so_far;
    }
};
