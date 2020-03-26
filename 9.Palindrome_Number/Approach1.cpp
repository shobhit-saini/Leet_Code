/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/
class Solution {
public:
    bool isPalindrome(int x) {
        int i, j;
        vector<int>v;
        if(x < 0)
        {
            return false;
        }
        while(x >= 1)
        {
            v.insert(v.begin(), x % 10);
            x = x / 10;
        }
        j = v.size() - 1; 
        for(i = 0; i < v.size()/2; i++)
        {
            if(v[i] != v[j])
                return false;
            j--;
        }
        return true;
    }
};
