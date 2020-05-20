/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int, greater<int>>mp1;
        multimap<int, int, greater<int>>mp2;
        vector<int>v;
        int size = nums.size(), count = 0;
        for( int i = 0; i < size; i++ )
        {
            mp1[nums[i]] += 1;
        }
        map<int, int>:: iterator itr;
        for( itr = mp1.begin(); itr != mp1.end(); itr++ )
        {
            mp2.insert({itr->second, itr->first});
        }
        for( itr = mp2.begin(); count < k; itr++,count++ )
        {
            v.push_back(itr->second);
        }
        return v;
    }
};
