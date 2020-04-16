class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int i , size = nums.size();
        vector<int> v;
        for( i = 0 ; i < size ; i++ )
        {
           if(nums[abs(nums[i]) - 1] < 0)
               v.push_back(abs(nums[i]));
            else if( nums[abs(nums[i]) - 1] > 0 )
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1] ;
        }
        return v ;
    }
};
