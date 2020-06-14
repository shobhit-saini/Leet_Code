/*
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:

1 <= arr.length <= 10^5
1 <= arr[i] <= 10^9
0 <= k <= arr.length

*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        int i, size = arr.size(), res = 0;
        map<int, int>mp;
        multimap<int, int>mp1;
        for( i = 0; i < size; i++ )
        {
            mp[arr[i]]++;
        }
        
        map<int, int>::iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            mp1.insert({itr->second, itr->first});
        }
        
        multimap<int, int>::iterator itr1;
        for( itr1 = mp1.begin(); itr1 != mp1.end(); itr1++ )
        {
            k = k - itr1->first;
            if( k < 0 )
            {
                res++;
            }
        }
        return res;
    }
};
