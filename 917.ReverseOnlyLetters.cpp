/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
*/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        
        int size = S.size(), i = 0, j = size-1, temp;
        
        while( i <= j )
        {
            if( ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122)) && ((S[j] >= 65 && S[j] <= 90) || (S[j] >= 97 && S[j] <= 122)))
            {
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
                i++; j--;
            }
            else
            {
                if( (S[i] < 65 || S[i] > 90) && (S[i] < 97 || S[i] > 122))
                {
                    i++;
                }
                if( (S[j] < 65 || S[j] > 90) && (S[j] < 97 || S[j] > 122) )
                    j--;
            }
        }
        return S;
    }
};
