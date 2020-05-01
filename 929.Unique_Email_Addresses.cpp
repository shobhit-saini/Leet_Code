/*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 

Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        int size = emails.size() , i , j , flag = 0 ;
        string str = "" ;
        map< string , int > mp ;
        for( i = 0 ; i < size ; i++ )
        {
            str = "" ;
            flag = 0 ;
            for(j = 0 ; j < emails[i].size() ; j++)
            {
                if( emails[i][j] == '.' && flag == 0 )
                {
                    
                }
                else if( emails[i][j] == '@' )
                {
                    flag = 1 ;
                    str += emails[i][j] ;
                    
                }
                else if( emails[i][j] == '+' )
                {
                    while( emails[i][j] != '@' )
                    {
                        j++ ;
                    }
                    j-- ;
                }
                else
                {
                    str += emails[i][j] ;
                }
            }
            mp[str] = 1 ;
        }
        
        return mp.size() ;
    }
};
