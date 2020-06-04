/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int i, size = nums.size(), bucket_index;
        if( size < 2 )
            return 0;
        
        int maxi = *max_element( nums.begin(), nums.end() );
        int mini = *min_element( nums.begin(), nums.end() );
        
        // Bucket size calculation
        int bucket_size = max( 1, (maxi - mini)/(size-1) );
        
        // Number of buckets
        int num_of_buckets = ((maxi-mini)/bucket_size) + 1;
        
        vector<int>maxi_b(num_of_buckets, INT_MIN);
        vector<int>mini_b(num_of_buckets, INT_MAX);
        
        for( i = 0; i < size; i++ )
        {
            bucket_index = (nums[i]-mini)/bucket_size;
            maxi_b[bucket_index] = max(maxi_b[bucket_index], nums[i]);
            mini_b[bucket_index] = min(mini_b[bucket_index], nums[i]);
        }
        int pre_bucket_max = mini, max_gap = 0;
        for( i = 0; i < num_of_buckets; i++ )
        {
            if( maxi_b[i] == INT_MIN )
                continue;
            if( max_gap < ( mini_b[i] - pre_bucket_max) )
                max_gap = mini_b[i] - pre_bucket_max;
            pre_bucket_max = maxi_b[i];
        }
        return max_gap;
    }
};
