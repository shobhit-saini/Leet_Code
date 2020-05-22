/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution {
public:
    int partition( vector<int>&nums, int p, int r )
    {
        int x = nums[r], i = p - 1, temp, j;
        for( j = p; j < r; j++ )
        {
            if( nums[j] <= x )
            {
                i = i + 1;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        temp = nums[r];
        nums[r] = nums[i+1];
        nums[i+1] = temp;
        return i+1;
    }
    int Quick_sort( vector<int>&nums, int& index, int p, int r)
    {
        if( p <= r )
        {
            int q = partition( nums, p, r );
            if( index == q )
                return nums[index];
            else if( index < q )
                return Quick_sort( nums, index, p, q-1 );
            else
                return Quick_sort( nums, index, q+1, r );
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        random_shuffle(nums.begin(), nums.end()); 
        int size = nums.size(), index = size - k, p = 0, r = size-1;
        return Quick_sort( nums, index, p, r );
    }
};
