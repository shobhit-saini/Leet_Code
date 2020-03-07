/*
Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> brr;
        int count = 1, i, j;
        for(i = 0; i < arr.size()-1; i++)
        {
            if(arr[i] == arr[i+1])
            {
                count += 2;
            }
            else
            {
                brr.push_back(count);
                count = 1;
            }
        }
        if(arr[arr.size()-2] != arr[arr.size()-1])
        {
            brr.push_back(count);
        }
        sort(brr.begin(), brr.end());
        for(i = 0; i < brr.size()-1; i++)
        {
            if(brr[i] == brr[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
