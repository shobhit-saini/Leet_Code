/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int size = nums.size() , i , j = size - 1 , tmp ;
        for( i = 0 ; i  < size ; i++ )
        {
            if( nums[i] <= 0 && i <= j)
            {
                tmp = nums[i] ;
                nums[i] = nums[j] ;
                if( nums[j] <= 0 )
                    i-- ;
                nums[j] = tmp ;
                j-- ;
            }
        }
        for( i = 0 ; i <= j ; i++ )
        {
            if(abs(nums[i]) - 1 <= j )
                nums[abs(nums[i]) - 1] = (nums[abs(nums[i]) - 1]) < 0 ? nums[abs(nums[i]) - 1] : -nums[abs(nums[i]) - 1] ; 
        }

        for( i = 0 ; i <= j ; i++ )
        {
            if( nums[i] > 0 )
                return i + 1 ;
        }
        return j + 2 ;
    }
};
