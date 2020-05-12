/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int size = nums.size(), low = 0, high = size-1, mid;
        while( low <= high )
        {
            mid = (low+high)/2;
            if( mid%2 == 0 )
            {
                if( mid+1 < size && nums[mid] == nums[mid+1] )
                    low = mid+1;
                else if( mid-1 >= 0 && nums[mid] == nums[mid-1])
                    high = mid-1;
                else
                    break;
            }
            else
            {
                if( mid-1 >= 0 && nums[mid] == nums[mid-1] )
                    low = mid+1;
                else if( mid+1 < size && nums[mid] == nums[mid+1] )
                    high = mid-1;
                else
                    break;
            }
        }
        return nums[mid];
    }
};
