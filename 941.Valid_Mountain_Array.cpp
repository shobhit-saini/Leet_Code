/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]


 

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 
 
*/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        
        int size = A.size(), i, flag1 = 0, flag2 = 0;
        if( size < 3 )
            return false;
        for( i = 0; i < size-1; i++ )
        {
            if( flag1 == 0 )
            {
                if( A[i] > A[i+1] )
                {
                    if( i == 0 )
                        return false;
                    flag1 = 1;
                    if( i == size-2 )
                        flag2 = 1;
                }
                else if( A[i] == A[i+1] )
                    return false;
            }
            else
            {
                flag2 = 1;
                if( A[i] <= A[i+1] )
                    return false;
            }
        }
        if( flag2 == 0 )
            return false;
        return true;
    }
};
