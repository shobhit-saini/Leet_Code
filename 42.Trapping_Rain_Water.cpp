/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        
        if( height.size() == 0 )
        {
            return 0 ;
        }
        int size = height.size() , i , lr_arr[size] , rl_arr[size] , area = 0 ;
        for( i = 0 ; i < size ; i++ )
        {
            if( i == 0 )
                lr_arr[0] = height[0];
            else
            {
                lr_arr[i] = height[i] > lr_arr[i - 1] ? height[i] : lr_arr[i - 1];
            }
        }

        for( i = size - 1 ; i >= 0 ; i-- )
        {
            if( i == size - 1 )
                rl_arr[i] = height[i];
            else
            {
                rl_arr[i] = height[i] > rl_arr[i + 1] ? height[i] : rl_arr[i + 1];
            }
        }
        for( i = 1 ; i < size -1 ; i++ )
        {
            area += ( lr_arr[i] < rl_arr[i] ? lr_arr[i] : rl_arr[i] ) - height[i] ;
        }
        return area ;
    }
};
