/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        int a = nums[0], b = INT_MIN, c = INT_MIN, i, flag = 0, j, flag1 = 0;
        for(i = 1; i < nums.size(); i++)
        {
            if(flag == 0 && nums[i] != a)
            {
                flag = 1;
                b = nums[i];
            }
            else if(flag == 1 && nums[i] != a && nums[i] != b)
            {
                flag1 = 1; 
                c = nums[i];
                break;
            }
        }
        if(flag == 0)
            return a;
        if(flag1 == 0)
            return max(a,b);
        int maxi = max(a, max(b, c));
        int mini = min(a, min(b, c));
        if(a != maxi && a != mini)
            b = a;
        else if(c != maxi && c != mini)
            b = c;
        a = mini; c = maxi;
        //cout << a << b << c << i;
        for(j = i; j < nums.size(); j++)
        {
            if(nums[j] > c)
            {
                a = b;
                b = c;
                c = nums[j];
            }
            if(nums[j] < c && nums[j] > b)
            {
                a = b;
                b = nums[j];
            }
            if(nums[j] < c && nums[j] < b && nums[j] > a )
                a = nums[j];
        }
        return a;
    }
};
