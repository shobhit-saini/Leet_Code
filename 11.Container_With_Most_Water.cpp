/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size() , i = 0 , j = size - 1 , area  , maxar = 0 , min ;
        while( i  < j )
        {
            min  = height[i] < height[j] ? height[i] : height[j] ;
            area = min * (j - i) ;
            if( maxar < area ) 
                maxar = area ;
            if( min == height[i] )
                i++ ;
            else
                j-- ;
        }
        return maxar ;
    }
};
