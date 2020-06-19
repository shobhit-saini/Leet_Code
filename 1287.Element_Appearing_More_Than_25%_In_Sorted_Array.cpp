/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

Return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
 

Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int size = arr.size(), i;
        int ws = (size/4);
        for( i = 0; i < size-ws; i++ )
        {
            if( arr[i] == arr[i+ws] )
                return arr[i];
        }
        return -1;
    }
};
