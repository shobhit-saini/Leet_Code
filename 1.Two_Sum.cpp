/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int>m;
        vector<int> v;
        int i, sum = 0 ;
        for(i = 0; i < nums.size(); i++)
        {
            m.insert(make_pair(nums[i], i));
        }
        multimap<int, int>::iterator itr, itr1;
        for(itr = m.begin(), itr1 = --m.end(); itr != itr1;)
        {
            sum = itr->first + itr1->first;
            if(sum == target)
            {
                v.push_back(itr->second);
                v.push_back(itr1->second);
                break;
            }
            else if(sum < target)
            {
                itr++;
            }
            else
            {
                itr1--;
            }
            
        }
       return v; 
    }
};
