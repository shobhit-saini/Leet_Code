/*
Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int size = arr.size(), low = 0, high = size - k, mid;
        while( low < high )
        {
            mid = (low + high)/2;
            if( x - arr[mid] > arr[mid+k] - x )
            {
                low = mid+1;
            }
            else
                high = mid;
        }
        vector<int>res(arr.begin()+low, arr.begin() + low + k);
        return res;
    }
};
