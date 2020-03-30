/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>v(amount+1);
        int i, j, temp, min;
        long val;

        v[0] = 0;
        for(i = 1; i <= amount; i++)
        {
            v[i] = -1;
        }
        for(i = 0; i < coins.size(); i++)
        {
            if(coins[i] <= amount)
            {
                v[coins[i]] = 1;
            }
            
        }
        for(i = 1; i <= amount; i++)
        {
            if(v[i] == -1)
            {
                min = INT_MAX;
                val;
                for(j = 0; j < coins.size(); j++)
                {
                    temp = i - coins[j];
                    if(temp > 0)
                    {
                        if(v[temp] == -1)
                        {
                            val = INT_MAX;
                        }
                        else
                        {
                            val = v[temp] + 1;
                        }
                        if(val < min)
                        {
                            min = val;
                        }
                    }
                }
                if(min == INT_MAX)
                {
                    v[i] = -1;
                }
                else
                {
                    v[i] = min;
                }
            }
        }
        return v[amount];
    }
};
