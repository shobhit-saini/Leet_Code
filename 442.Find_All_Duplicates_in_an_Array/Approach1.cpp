/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i , size = nums.size() , arr[size + 1];
        vector<int> v;
        
        for( i = 0 ; i  <= size ; i++ )
        {
            arr[i] = 0 ;
        }
        for( i = 0 ; i < size ; i++ )
        {
            arr[nums[i]] += 1 ; 
        }
        for( i = 0 ; i <= size ; i++ )
        {
            if( arr[i] == 2 )
                v.push_back(i) ;
        }
        return v ;
    }
};
