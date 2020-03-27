/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
class Solution {
public:
    bool isHappy(int n) {
        vector<int> v;
        map<int, int>mp;
        int i, happy= n;
        if(n == 0)
            return false;
        while(happy != 1)
        {
            while(happy >= 1)
            {
                v.insert(v.begin(), happy%10);
                happy = happy/10;
            }
            happy = 0;
            for(i = 0; i < v.size(); i++)
            {
                happy += v[i]*v[i];
            }
            if(mp.find(happy) != mp.end())
                return false;
            mp[happy] += 1;
            v.clear();
        }
        return true;
        
    }
};
