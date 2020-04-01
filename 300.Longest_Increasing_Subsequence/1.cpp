/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int arr[nums.size()], i, j, max = 1;
        if(nums.size() == 0)
            return 0;
        for(i = 0; i < nums.size(); i++)
        {
            arr[i] = 1;
        }
        for(i = 1; i < nums.size(); i++)
        {
            for(j = 0; j <= i; j++)
            {
                if(nums[i] > nums[j])
                    arr[i] = (arr[i] > arr[j]+1) ? arr[i] : arr[j]+1;
            }
            if(max < arr[i])
                max = arr[i];
        }
        return max;
    }
};
