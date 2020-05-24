/*
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
Example 2:

Input: nums1 = [3,-2], nums2 = [2,-6,7]
Output: 21
Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
Their dot product is (3*7) = 21.
Example 3:

Input: nums1 = [-1,-1], nums2 = [1,1]
Output: -1
Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
Their dot product is -1.
*/
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int size1 = nums1.size(), size2 = nums2.size(), dp[size1+1][size2+1], maxi = INT_MIN, i, j, temp = 0, k;
        for( i = 0; i <= size1; i++ )
        {
            dp[i][0] = 0;
        }
        for( i = 0; i <= size2; i++ )
        {
            dp[0][i] = 0;
        }
        for( i = 1; i <= size1; i++ )
        {
            for( j = 1; j <= size2; j++  )
            {
                dp[i][j] = (nums1[i-1]*nums2[j-1]);
                dp[i][j] += max(0, dp[i-1][j-1]);
                if( i-1 > 0 && dp[i-1][j] > dp[i][j] )
                    dp[i][j] = dp[i-1][j];
                if( j-1 > 0 && dp[i][j-1] > dp[i][j] )
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[size1][size2];
    }
};
