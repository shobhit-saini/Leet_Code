class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int i , j , size = nums.size() , sum = 0 ;
        for( i = 0 ; i < size ; i++ )
        {
            sum = nums[i] ;
            for( j = i + 1 ; j < size ; j++ )
            {
                sum += nums[j]  ;
                if( k == 0 && sum == k)
                    return true ;
                else if( k != 0 && sum % k == 0 )
                    return true ;
            }
        }
        return false ;
    }
};
