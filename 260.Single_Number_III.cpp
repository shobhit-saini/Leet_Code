/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int i, size = nums.size(), xor_all = 0, num1 = 0, num2 = 0, bit = 0;
        vector<int>res;
        for( i = 0; i < size; i++ )
        {
            xor_all ^= nums[i];
        }
        
        bit = (xor_all) & (-xor_all);
        
        for( i = 0; i < size; i++ )
        {
            if( (nums[i] & bit) == 0 )
                num1 ^= nums[i];
            else
                num2 ^= nums[i];
        }
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};
