/*
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
class NumArray {
public:
    vector<int>v ;
    NumArray(vector<int>& nums) {
        
        int i , size = nums.size() ;
        v.push_back(0) ;
        for( i = 0 ; i < size ; i++ )
        {
            v.push_back(v[i] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        
        return v[j + 1] - v[i] ;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
