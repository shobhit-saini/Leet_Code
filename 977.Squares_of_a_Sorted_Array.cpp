/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int i = 0 , j = A.size() - 1 , val ;
        vector<int> :: iterator itr = A.begin() ;
        while ( A[i] < 0 && i < j )
        {
                if( abs(A[i]) < (A[j]) )
                    j-- ;
                else
                {
                    A.insert(itr + j + 1 , abs(A[i])) ;
                    i++ ;
                }
        }
        A.erase(itr , itr + i ) ;
        for( i = 0 ; i < A.size() ; i++ )
        {
            A[i] = A[i] * A[i] ;
        }
        return A ;
    }
};
