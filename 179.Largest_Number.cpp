/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    static int Comp( string x , string y )
    {
        string xy = x.append(y) ;
        string yx = y.append(x) ;
        return xy.compare(yx) > 0 ? 1 : 0 ;
    }
    string largestNumber(vector<int>& nums) {
        
        vector<string>str ;

        string s = "" ;
        int flag = 0 , flag1 = 0 , i , size = nums.size() ; 
        if( size == 0 )
            return s ;
        for( i = 0 ; i < size ; i++ )
        {
            str.push_back( to_string( nums[i] ) ) ;
        }
        sort( str.begin() , str.end() , Comp ) ;
        for( i = 0 ; i < size ; i++ )
        {
            if( str[i] == "0" && flag == 0  )
            {
                if( flag1 == 0 )
                {
                    s += str[i] ;
                    flag1 = 1 ;
                }
            }
            else
            {
                flag = 1 ;
                s += str[i] ;
            }
        }
        return s ;
    }
};
