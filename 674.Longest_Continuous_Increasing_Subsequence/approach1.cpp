class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0)
            return 0;
        int i, maxi = 1, count = 1;
        for(i = 1; i < size; i++)
        {
            if(nums[i] > nums[i-1])
                count++;
            else
                count = 1;
            if(maxi < count)
                    maxi = count;
        }
        return maxi;
    }
};
