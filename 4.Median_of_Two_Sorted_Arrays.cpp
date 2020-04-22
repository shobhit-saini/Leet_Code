/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
class Solution {
public:
    double median = 0.0 ;
    double median_fun( vector<int>& nums1 , vector<int>& nums2 , int start , int end , int overall_partition , int flag ,int size1 , int size2 )
    {
        
        if( start <= end )
        {
            int partition_nums1 = (start + end) / 2 ;
            int partition_nums2 = overall_partition - partition_nums1 ;
            int left_max_nums1 = partition_nums1  == 0 ?  INT_MIN : nums1[partition_nums1 - 1] ;
            int left_max_nums2 = partition_nums2  == 0 ? INT_MIN : nums2[partition_nums2 - 1] ;
            int right_min_nums1 = partition_nums1 == size1 ? INT_MAX : nums1[partition_nums1] ;
            int right_min_nums2 = partition_nums2 == size2 ? INT_MAX : nums2[partition_nums2] ;
            if( left_max_nums1 <= right_min_nums2 && right_min_nums1 >= left_max_nums2 )
            {
                if( flag == 1 )
                {
                    median = (double(max(left_max_nums1 , left_max_nums2) + min(right_min_nums1 , right_min_nums2))) / 2 ;
                }
                else
                    median = double(max(left_max_nums1 , left_max_nums2)) ;
                return median ;
            }
            else if( left_max_nums1 > right_min_nums2 )
                 return median_fun( nums1 , nums2 ,start , partition_nums1 - 1, overall_partition , flag , size1 , size2 ) ;
            else
                 return median_fun( nums1 , nums2 , partition_nums1 + 1 , end  , overall_partition , flag ,size1 , size2 ) ; 
        }
        return median ;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size1 = nums1.size() , size2 = nums2.size() , flag = 0 ;
        int overall_partition = (size1 + size2 + 1) / 2 ;
        if((size1 + size2) % 2 == 0 )
            flag = 1 ;
        if( size1 > size2 )
            return median_fun( nums2 , nums1 , 0 , size2 , overall_partition , flag , size2 , size1) ;
        else
            return median_fun( nums1 , nums2 , 0 , size1 , overall_partition , flag , size1 , size2) ;
    }
};
