/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int size = nums.size() , i , count = 0 , max = 0 ;
        if( size == 0 )
            return max ;
        map< int , int > mp ;
        for( i = 0 ; i < size ; i++ )
        {
            mp[nums[i]] += 1 ;
        }
        map<int , int> :: iterator itr1 = mp.begin() , itr2;
        itr2 = itr1 ;
        itr2++ ;
        for( ; itr2 != mp.end() ; itr1++ ,itr2++ )
        {
            if( (itr2 -> first - itr1 -> first) == 1 )
                count++ ;
            else
            {
                if( max < count )
                    max = count ;
                count = 0 ;
            }
        }
        return max > count ? max + 1 : count + 1 ;
        
    }
};
