/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        set<pair<int, int>>s;
        long sum;
        int var = 0, i, j, size = nums1.size(), size1 = nums2.size();
        vector<int>v1;
        vector<vector<int>>v2;
        if( k == 0 )
            return v2;
        if( nums1.size() == 0 || nums2.size() == 0 )
            return v2;
        priority_queue<pair<long, pair<long, long>>, vector<pair<long, pair<long, long>>>, greater<pair<long, pair<long, long>>>>pq;
        pair<long, long>tmp = {0, 0};
        sum = nums1[0] + nums2[0];
        pair<long, pair<long, long>>ele = {sum, tmp};
        pq.push( ele );
        k = k <= size*size1 ? k : size*size1;
        while( var < k && !pq.empty() )
        {
            ele = pq.top();
            pq.pop();
            i = ele.second.first;
            j = ele.second.second;
            v1.push_back(nums1[i]);
            v1.push_back(nums2[j]);
            v2.push_back(v1);
            if( i + 1 < size )
            {
                sum = nums1[i+1] + nums2[j];
                tmp = {i+1, j};
                if( s.find(tmp) == s.end() )
                {
                    s.insert(tmp);
                    ele = {sum, tmp};
                    pq.push(ele);
                }  
            }
            
            if( j + 1 < size1 )
            {
                sum = nums1[i] + nums2[j+1];
                tmp = {i, j+1};
                if( s.find(tmp) == s.end() )
                {
                    s.insert(tmp);
                    ele = { sum, tmp };
                    pq.push(ele);
                }
            }
            var++;
            v1.clear();
        }
        return v2;
    }
};
