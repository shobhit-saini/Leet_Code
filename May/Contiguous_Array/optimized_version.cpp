class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int size = nums.size(), i, t1, max_len = 0;
        t1 = 0;
        map<int, int>mp;
        mp[0] = 0;
        for( i = 1; i <= size; i++ )
        {
            if( nums[i-1] == 0 )
            {
                t1--;
            }
            else
            {
                t1++;
            }
            if( mp.find(t1) != mp.end() )
            {
                if( max_len < (i-mp[t1]) )
                    max_len = (i - mp[t1]);
            }
            else
                mp[t1] = i;
        }
        return max_len;
    }
};
