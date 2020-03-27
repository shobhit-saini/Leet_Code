class Solution {
public:
    bool containsDuplicate(vector<int>& A) {
        map<int, int>mp;
        int i;
        if(A.size() == 0)
        {
            return false;
        }
        for(i = 0; i < A.size(); i++)
        {
            mp[A[i]] += 1;
        }
        map<int, int>::iterator itr;
        for(itr = mp.begin(); itr != mp.end(); itr++)
        {
            if(itr->second > 1)
                return true;
        }
        return false;
    }
};
