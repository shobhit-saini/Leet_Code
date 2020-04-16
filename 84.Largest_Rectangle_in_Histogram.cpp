/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s ;
        int area = 0 , top = -1 , i = 0 , max = 0 , val , size = heights.size();
        if( size == 0 )
            return 0 ;
        s.push(i) ;
        i++ ;
        while( !s.empty() )
        {
            if( i < size &&  heights[i] >= heights[s.top()] )
            {
                s.push(i) ;
                i++ ;
            }
            else
            {
                val = s.top() ;
                s.pop() ;
                if( s.empty() )
                {
                    area = heights[val] * i ;
                    if( i < size )
                    {
                        s.push(i) ;
                        i++ ;
                    }
                }
                else
                    area = heights[val] * (i - s.top() - 1) ;
                if( max < area )
                    max = area ;
            }
        }
        return max ;
    }
};
