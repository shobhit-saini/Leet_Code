class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int start = 0, i;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                nums[start] = nums[i];
                start++;
            }
        }
        return start;
    }
};
