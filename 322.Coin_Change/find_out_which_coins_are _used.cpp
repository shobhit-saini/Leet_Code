class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int arr[amount+1], i, j, min, index;
        int backlinks[amount+1];
        backlinks[0] = -2;
        for(i = 0; i < coins.size(); i++)
        {
            if(coins[i] <= amount)
                arr[coins[i]] = 1;
        }
        for(i = 0; i <= amount; i++)
        {
            arr[i] = -1;
        }
        arr[0] = 0;
        for(i = 1; i <= amount; i++)
        {
            min = INT_MAX;
            index = -1;
            for(j = 0; j < coins.size(); j++)
            {
                if((i - coins[j]) >= 0)
                {
                    
                    if(min > (arr[i - coins[j]]+1) && arr[i - coins[j]] != -1)
                    {
                        min = arr[i - coins[j]] + 1;
                        index = i - coins[j];
                    }
                }
            }

            arr[i] = min == INT_MAX ? -1 : min;
            backlinks[i] = index; 
        }
        i = amount;
        cout << "Coins used: ";
        while(backlinks[i] != -2)
        {
            if(backlinks[i] == -1)
                break;
            cout << i - backlinks[i]  << " ";
            i = backlinks[i];
            
        }
        
       
        return arr[amount];
    }
};
