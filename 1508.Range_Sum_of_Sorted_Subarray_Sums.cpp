/*
Given the array nums consisting of n positive integers. You computed the sum of all non-empty continous subarrays from the array and then sort them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 10^9 + 7.

 

Example 1:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13 
Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
Example 2:

Input: nums = [1,2,3,4], n = 4, left = 3, right = 4
Output: 6
Explanation: The given array is the same as example 1. We have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 3 to ri = 4 is 3 + 3 = 6.
Example 3:

Input: nums = [1,2,3,4], n = 4, left = 1, right = 10
Output: 50
 

Constraints:

1 <= nums.length <= 10^3
nums.length == n
1 <= nums[i] <= 100
1 <= left <= right <= n * (n + 1) / 2
*/
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        int i, j, size = nums.size(), flag = 0, sum = 0;
        vector<int>v;
        for( i = 0; i < size; i++ )
        {
            flag = 0;
            for( j = i; j < size; j++ )
            {
                if( flag == 0 )
                {
                    v.push_back(nums[j]);
                    flag = 1;
                }
                else
                {
                    v.push_back(nums[j] + v.back());
                }
            }
        }
        sort(v.begin(), v.end());
   
        for( i = left-1; i < right; i++ )
        {
            sum = (sum + v[i]) % 1000000007;
        }
        return sum;
    }
};
///////////////////////////////////////////////////Solution-2////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        int i, res = 0;
        for( i = 0; i < n; i++ )
        {
            pq.push({nums[i], i+1});
        }
        
        for( i = 1; i <= right; i++ )
        {
            auto p = pq.top();
            pq.pop();
            if( left <= i )
            {
                res += p.first;
            }
            if( p.second < n )
            {
                pq.push({ p.first + nums[p.second++], p.second });
            }
        }
        return res;
    }
};
