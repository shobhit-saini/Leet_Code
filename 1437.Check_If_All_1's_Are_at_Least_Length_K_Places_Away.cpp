/*
Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.

 

Example 1:



Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:



Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
Example 3:

Input: nums = [1,1,1,1,1], k = 0
Output: true
Example 4:

Input: nums = [0,1,0,1], k = 1
Output: true
 

Constraints:

1 <= nums.length <= 10^5
0 <= k <= nums.length
nums[i] is 0 or 1
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        map<int , int>mp;
        int i, size = nums.size();
        for( i = 0; i < size; i++ )
        {
            if( nums[i] == 1 )
                mp[i] = 1;
        }
        if( mp.size() == 0 || mp.size() == 1 )
            return true;
        map<int , int>::iterator itr1 = mp.begin() , itr2 = itr1;
        itr2++;
        for( ; itr2 != mp.end(); itr1++, itr2++ )
        {
            if( (itr2 -> first - itr1 -> first - 1) < k  )
                return false;
        }
        return true;
    }
};
