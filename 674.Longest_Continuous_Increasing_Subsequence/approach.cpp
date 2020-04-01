/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
Note: Length of the array will not exceed 10,000.
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        int i, size = nums.size(), arr[size], maxi = 1;
        arr[0] = 1;
        for(i = 1; i < size; i++)
        {
            if(nums[i] > nums[i-1])
            {
                arr[i] = arr[i-1] + 1;
            }
            else
                arr[i] = 1;
            if(maxi < arr[i])
                    maxi = arr[i];
        }
        return maxi;
    }
};
