class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int arr[amount + 1], i, j;
        for(i = 1; i <= amount; i++)
        {
            arr[i] = 0;
        }
        arr[0] = 1;
        for(i = 0; i < coins.size(); i++)
        {
            for(j = coins[i]; j <= amount; j++)
            {
                arr[j] += arr[j - coins[i]];
            }
        }
        return arr[amount];
    }
};
