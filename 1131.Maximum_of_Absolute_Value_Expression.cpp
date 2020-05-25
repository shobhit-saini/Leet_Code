/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        
        int size1 = arr1.size(), i, max1 = INT_MIN, min1 = INT_MAX, max2 = INT_MIN, min2 = INT_MAX, max3 = INT_MIN, min3 = INT_MAX, max4 = INT_MIN, min4 = INT_MAX;
        for( i = 0; i < size1; i++ )
        {
            max1 = max(arr1[i]+arr2[i]+i, max1);
            min1 = min(arr1[i]+arr2[i]+i, min1);
            max2 = max(arr1[i] + arr2[i] - i, max2);
            min2 = min(arr1[i] + arr2[i] - i, min2);
            max3 = max(arr1[i] - arr2[i] - i, max3);
            min3 = min(arr1[i] - arr2[i] - i, min3);
            max4 = max(arr1[i] - arr2[i] + i, max4);
            min4 = min(arr1[i] - arr2[i] + i, min4);
        }
        return max(max1-min1,max(max2-min2, max(max3-min3, max4-min4)));
    }
};
