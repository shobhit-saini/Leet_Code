/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        stack<int> s ;
        if( nums.size() == 0 || nums.size() == 1 )
            return 0 ;
        int i = 0 , j , flag = 0 ,start = INT_MAX , end = -1 , a = -1 , max ; 
        while( i < nums.size() )
        {
            if( s.empty() )
            {
                s.push(i) ; 
            }
            else
            {
                if( nums[s.top()] < nums[i] )
                    s.push(i) ;
                else if( nums[s.top()] == nums[i] )
                {
                    if( end == s.top() )
                    {
                        s.push(i) ;
                        end = i ;
                    }
                    else 
                        s.push(i) ;
                }
                else if( nums[s.top()] > nums[i] )
                {
                    end = i ;
                    max = i ;
                    while( !s.empty() && nums[s.top()] > nums[i] )
                    {
                        a = s.top() ;
                        if( nums[max] < nums[a] )
                            max = a ;
                        s.pop() ;
                    }
                    s.push(max);
                    if( start > a )
                        start = a ;
                }
            }
            i++ ;
        }
        if( s.size() == nums.size() )
            return 0 ;
        return end - start + 1 ;
    }
};
