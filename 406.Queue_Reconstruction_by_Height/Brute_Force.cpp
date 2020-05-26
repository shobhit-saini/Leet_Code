/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 
*/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        multimap<int, int>mp;
        vector<vector<int>>res;
        vector<int>v;
        int size = people.size(), i, j, count = 0;
        for( i = 0; i < size; i++ )
        {
            mp.insert({people[i][0], people[i][1]});
        }
        multimap<int, int>::iterator itr;
        i = 0;
        while( res.size() != size )
        {
            v.clear();
            for( itr = mp.begin(); itr != mp.end(); itr++ )
            {
                count = 0;
                if( itr -> second <= i )
                {
                    if( res.size() == 0 || itr->second == 0 ){
                        v.push_back(itr->first);
                        v.push_back(itr->second);
                        res.push_back(v);
                        mp.erase(itr);
                        i++;
                        break;
                    }
                    else
                    {
                        for( j = res.size()-1; j >= 0; j-- )
                        {
                            if(res[j][0] >= itr->first)
                                count++;
                        }
                        if( count == itr->second )
                        {
                            v.push_back(itr->first);
                            v.push_back(itr->second);
                            res.push_back(v);
                            mp.erase(itr);
                            i++;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
