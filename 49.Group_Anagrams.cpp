/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        int size = strs.size() , i , k = 0 ;
        vector<vector<string>> v ;
        unordered_map<string , vector<string>> mp ;
        string s ;
        for( i = 0 ; i < size ; i++ )
        {
            s = strs[i] ;
            sort( s.begin() , s.end() ) ;
            mp[s].push_back(strs[i]) ;
        }
        unordered_map<string , vector<string>>:: iterator itr ;
        for( itr = mp.begin() ; itr != mp.end() ; itr++ )
        {
            v.push_back(itr -> second) ;
        }
        return v ;
    }
};
