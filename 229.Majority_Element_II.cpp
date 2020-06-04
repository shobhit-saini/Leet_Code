/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0, count2 = 0, i, size = nums.size(), first = INT_MAX, second = INT_MAX, var1 = 0, var2 = 0;
        vector<int>res;
        if( size == 1 || size == 0 )
            return nums;
        for( i = 0; i < size; i++ )
        {
            if( first == nums[i] )
                count1++;
            else if( second == nums[i] )
                count2++;
            else if( count1 == 0 )
            {
                first = nums[i];
                count1++;
            }
            else if( count2 == 0 )
            {
                second = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        for( i = 0; i < size; i++ )
        {
            if( nums[i] == first )
                var1++;
            if( nums[i] == second )
                var2++;
        }
        if( var1 > size/3 )
            res.push_back(first);
        if( var2 > size/3 )
            res.push_back(second);
        return res;
    }
};
