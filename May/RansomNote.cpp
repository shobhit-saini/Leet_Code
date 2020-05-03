/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int>mp;
        int i, size1 = ransomNote.size(), size2 = magazine.size();
        for( i = 0; i < size2; i++ )
        {
            mp[magazine[i]] += 1; 
        }
        for( i = 0; i < size1; i++ )
        {
            if( mp.find(ransomNote[i]) == mp.end() )
                return false;
            else
            {
                if(mp[ransomNote[i]] > 0)
                    mp[ransomNote[i]]--;
                else
                    return false;
            }
        }
        return true;
    }
};
