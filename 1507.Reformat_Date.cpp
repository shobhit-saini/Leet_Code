/*
Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.
 

Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"
Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"
Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"
 

Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.

*/
class Solution {
public:
    string reformatDate(string date) {
        
        int i = 0, size = date.size();
        string res = "", str = "";
        vector<string>v;
        map<string, string>mp;
        mp["Jan"] = "01";
        mp["Feb"] = "02";
        mp["Mar"] = "03";
        mp["Apr"] = "04";
        mp["May"] = "05";
        mp["Jun"] = "06";
        mp["Jul"] = "07";
        mp["Aug"] = "08";
        mp["Sep"] = "09";
        mp["Oct"] = "10";
        mp["Nov"] = "11";
        mp["Dec"] = "12";
        while( i < size )
        {
            if( date[i] == ' ' )
            {
                v.push_back(str);
                str = "";
            }
            else
            {
                str += date[i];
            }
            i++;
        }
        v.push_back(str);
        i = 0;
        str = "";
        while(1)
        {
            if( isdigit(v[0][i]) )
            {
                str += v[0][i];
            }
            else 
                break;
            i++;
        }
        res += v[2];
        res += "-";
        res += mp[v[1]];
        res += "-";
        if( str.size() == 1 )
        {
            str = "0" + str;
        }
        res += str;
        
        return res;
    }
};
