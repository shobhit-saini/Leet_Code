/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int i;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
        {
            return result;
        }
        int sum , low , high;
        for(i = 0; i < nums.size()-2; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                sum = -nums[i], low = i+1, high = nums.size()-1;
                while(low < high)
                {
                    if((nums[low] + nums[high]) == sum)
                    {
                        vector<int>row;
                        row.push_back(nums[i]);
                        row.push_back(nums[low]);
                        row.push_back(nums[high]);
                        result.push_back(row);
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(high > low && nums[high-1] == nums[high]) high--;
                        low++;
                        high--;
                      }
                    else if((nums[low] + nums[high]) < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }

                }
            }
        }
        return result;
    }
};
