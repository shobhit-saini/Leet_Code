/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int size = nums.size() , i , tmp , count ;
        tmp = nums[0] ; 
        count = 1 ;
        for( i = 1 ; i < size ; i++ )
        {
            if( count == 0 )
            {
                tmp = nums[i] ;
                count++ ;
            }
            else if( nums[i] == tmp )
                count++ ;
            else
                count-- ;
        }
        return tmp ;
    }
};
