/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, size = nums.size(), temp, tmp, j, index, max;
        for( i = size-1; i > 0; i-- )
        {
            if( nums[i-1] < nums[i] )
            {
                break;
            }
        }
        if( i == 0 )
        {
            sort( nums.begin(), nums.end() );
        }
        else
        {
            temp = nums[i-1];
            for( j = i; j < size; j++ )
            {
                if( temp < nums[j] )
                {
                    max = nums[j];
                    index = j;
                }
                else
                    break;
            }
            tmp = nums[i-1];
            nums[i-1] = nums[index];
            nums[index] = tmp;
            reverse(nums.begin() + i, nums.end());
        }
    }
};
