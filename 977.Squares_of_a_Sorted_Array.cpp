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
///////// Approach 1///////////
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int i = 0 , j = 0 , size = A.size() , val , k ;
        vector<int> v1 ;
        while( i < size &&  A[i] < 0 )
        {
            i++ ;
        }
        
        k = i - 1 ;
        j = i ;
        while( j < size && k >= 0 ) 
        {
            if( A[j] < abs(A[k]) )
            {
                v1.push_back( A[j]*A[j] ) ;
                j++ ;
            }
            else
            {
                v1.push_back( A[k]*A[k] ) ;
                k-- ;
            }
        }
        i = j ;
        while( i < size )
        {
            v1.push_back(A[i]*A[i]) ;
            i++ ;
        }
        while( k >= 0 )
        {
            v1.push_back( A[k]*A[k] ) ;
            k-- ;
        }
        return v1 ;
    }
};
/////////////Approach 2//////////////////
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int i = 0 , size = A.size() , val , j = size - 1 , k = j ;
        vector<int> v1(size) ;
        while( i <= j ) 
        {
            if( abs(A[i]) < A[j] )
            {
                v1[k] = A[j]*A[j] ;
                j-- ;
            }
            else
            {
                v1[k] = A[i]*A[i] ;
                i++;
            }
            k--;
        }
        return v1 ;
    }
};
