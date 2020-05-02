/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/
class Solution {
public:
    void merge( vector<int>& nums , int low , int mid , int high )
    {
        int i = low , j = mid + 1 ;
        vector<int>out ;
        while( i <= mid && j <= high )
        {
            if( nums[i] < nums[j] )
            {
                out.push_back(nums[i]) ;
                i++ ;
            }
            else
            {
                
                out.push_back(nums[j]) ;
                j++ ;
            }
        }
        while( i <= mid )
        {
            out.push_back(nums[i]) ;
            i++ ;
        }
        while( j <= high )
        {
            out.push_back(nums[j]) ;
            j++ ;
        }
        for( i = low ; i <= high ; i++ )
        {
            nums[i] = out[i-low] ;
        }
    }
    void merge_sort(vector<int>& nums , int low , int high , int& count  )
    {
        if( low < high )
        {
            int mid = ( low + high ) / 2 ;
            merge_sort( nums , low , mid , count ) ;
            merge_sort( nums , mid + 1 , high , count ) ;
            for( int i = low , j = mid + 1 ; i <= mid && j <= high ; i++ )
            {
                    if( nums[i]/2.0 > nums[j] )
                    {
                        count += (mid - i + 1) ;
                        j++;
                        i--;
                    }
            }
            merge( nums , low , mid , high ) ;
        }
    }
    int reversePairs(vector<int>& nums) {
        
        vector<int>out(nums.size()) ;
        int count = 0;
        merge_sort( nums , 0 , nums.size() - 1 , count ) ; 
        return count;
    }
};
