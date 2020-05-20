/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
                
        map<string, int>mp1;
        multimap<int, string, greater<int>>mp2;
        vector<string>v;
        int size = words.size(), count = 0;
        for( int i = 0; i < size; i++ )
        {
            mp1[words[i]] += 1;
        }
        map<string, int>:: iterator itr;
        for( itr = mp1.begin(); itr != mp1.end(); itr++ )
        {
            mp2.insert({itr->second, itr->first});
        }
        multimap<int, string>:: iterator itr1;
        for( itr1 = mp2.begin(); count < k; itr1++,count++ )
        {
            v.push_back(itr1->second);
        }
        return v;
    }
};
