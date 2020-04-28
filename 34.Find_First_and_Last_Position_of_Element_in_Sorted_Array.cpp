/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int i , low = 0 , high = nums.size() - 1 , low1 , high1 , low2 , high2 , mid1 , mid2 , mid ;
        vector<int> v ;
        while( low <= high )
        {
            mid = (low + high) / 2 ;
            if( nums[mid] == target )
            {
                low1 = low ;
                high1 = mid - 1 ;
                low2 = mid + 1 ;
                high2 = high ;
                while( low1 <= high1 )
                {
                    mid1 = (low1 + high1) / 2 ;
                    if( nums[mid1] == target )
                        high1 = mid1 - 1 ;
                    else 
                        low1 = mid1 + 1 ;
                }
                while( low2 <= high2 )
                {
                    mid2 = (low2 + high2) / 2 ;
                    if( nums[mid2] == target )
                        low2 = mid2 + 1;
                    else 
                        high2 = mid2 - 1 ;
                }
                v.push_back(low1) ;
                v.push_back(high2) ;
                return v ;
            }
            else if( nums[mid] < target )
            {
                low = mid + 1 ;
            }
            else
            {
                high = mid - 1 ;
            }
        }
        v.push_back(-1) ;
        v.push_back(-1) ;
        return v ;
    }
};
