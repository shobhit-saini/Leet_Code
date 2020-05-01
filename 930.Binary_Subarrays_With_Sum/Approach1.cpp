/*
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.

*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        
        int i , size = A.size() , res = 0 , sum = 0 ; 
        map<int , int> mp ;
        mp[0] = 1 ;
        for( i = 0 ; i < size ; i++ )
        {
            sum += A[i] ;
            res += mp[sum - S] ;
            mp[sum]++ ;
        }
        return res ;
    }
};
