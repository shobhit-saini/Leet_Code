/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class Solution {
public:
    vector<int> intersect(vector<int>& a1, vector<int>& a2) {
        int i = 0, j = 0;
        vector<int> v;
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        while(i < a1.size() && j < a2.size())
        {
            if(a1[i] == a2[j])
            {
                v.push_back(a1[i]);
                i++; j++;
            }
            else if(a1[i] < a2[j])
                i++;
            else
                j++;
        } 
        return v;
    }
};
