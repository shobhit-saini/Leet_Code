/*
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        
        int i, j, size = A.size(), val, res = 0;
        map<int, int>mp;
        mp[0] = 1;
        for( i = 1; i < size; i++ )
        {
            A[i] += A[i-1];
        }
        for( i = 0; i < size; i++ )
        {
            mp[(A[i]%K + K)%K]++;
        }
        map<int, int>:: iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            val = itr->second;
            res += (val*(val-1))/2;
        }
        return res;
    }
};
