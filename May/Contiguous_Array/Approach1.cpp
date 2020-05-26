/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int size = nums.size(), i, t1[size+1], max_len = 0, max_t1 = 0, max_t2 = 0;
        t1[0] = 0;
        map<int, vector<int>>mp;
        mp[0].push_back(0);
        for( i = 1; i <= size; i++ )
        {
            if( nums[i-1] == 0 )
            {
                t1[i] = t1[i-1]-1;
            }
            else
            {
                t1[i] = t1[i-1] + 1;
            }
            mp[t1[i]].push_back(i);
        }
        map<int, vector<int>>::iterator itr;
        for( itr = mp.begin(); itr != mp.end(); itr++ )
        {
            if( (itr->second[(itr->second).size()-1] - itr->second[0]) > max_len )
                max_len = (itr->second[(itr->second).size()-1] - itr->second[0]);
        }

        return max_len;
    }
};
