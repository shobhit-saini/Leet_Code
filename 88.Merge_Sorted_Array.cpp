/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int size1 = nums1.size() , i = 0 , j = 0 , k = 0; 
        while( i < size1 && j < n )
        {
            if( nums1[i] <= nums2[j] &&  k < m  )
            {
                i++ ;
                k++;
            }
            else
            {
                nums1.insert( nums1.begin() + i , nums2[j] );
                i++ ;
                j++;
            }
        }
    vector<int>::iterator it1, it2; 
    it1 = nums1.begin() + size1 ; 
    it2 = nums1.end(); 
 
    nums1.erase(it1, it2); 
    }
};
