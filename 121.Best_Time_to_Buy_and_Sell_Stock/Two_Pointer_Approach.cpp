class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0)
            return 0;
        int i, j, size = prices.size(), min_pointer = 0, val, profit = 0;
        for( i = 1; i < size; i++ )
        {
            if( prices[min_pointer] > prices[i] )
            {
            
                min_pointer = i;    
            }
            else
            {
                val = prices[i] - prices[min_pointer];
                if(val > profit)
                    profit = val;
            }
        }
    
        return profit;
    }
};
