/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        int i, n1 = 2, n2 = 3, n3 = 5, temp;
        if(n == 1)
        {
            return 1;
        }
        int j = 0, k = 0, l =0;
        v.push_back(1);
        for(i = 1; i < n; i++)
        {
            temp = min(n1, min(n2, n3));
            v.push_back(temp);
            if(temp == n1)
            {
                j++;
                n1 = v[j]*2;
            }
            if(temp == n2)
            {
                k++;
                n2 = v[k]*3;
            }
            if(temp == n3)
            {
                l++;
                n3 = v[l]*5;
            }
        }
        return temp;
    }
};
