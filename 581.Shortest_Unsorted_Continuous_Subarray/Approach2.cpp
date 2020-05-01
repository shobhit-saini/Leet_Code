class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int i , start , end , size = nums.size() ;
        for( i = 0 ; i < size - 1 ; i++ )
        {
            if( nums[i] > nums[i + 1] )
                break ;
        }
        start = i ;
        if( start == size - 1 )
            return 0 ;
        for( i = size -1 ; i > 0 ; i-- )
        {
            if( nums[i - 1] > nums[i] )
                break ;
        }
        end = i ;
        
        int min = INT_MAX, max = INT_MIN ;
        for( i = start ; i <= end ; i++ )
        {
            if( min > nums[i] )
                min = nums[i] ;
            if( max < nums[i] )
                max = nums[i] ;
        }
        
        for( i = 0 ; i < start ; i++ )
        {
            if( nums[i] > min )
            {
                start = i ;
                break ;
            }
        }
        
        for( i = size - 1 ; i > end ; i-- )
        {
            if( nums[i] < max )
            {
                end = i ;
                break ;
            }
        }
        return end - start + 1 ;
    }
};
