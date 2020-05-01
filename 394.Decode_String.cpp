/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution {
public:
    string decodeString(string s) {
        
        int i , size = s.size() , j ,flag = 0 ; 
        stack<string>st ;
        string a = "" , b = "" , qtr = "" , str = "" , num = "" , res = ""; 
        for( i = 0 ; i < size ; i++ )
        {
            if( isdigit(s[i]) )
            {
                while( s[i] != '[' )
                {
                    num += s[i] ;
                    i++ ;
                }
                i-- ;
            }
            else if( s[i] == '[' )
            {
                flag = 1 ;
                st.push(num) ;
                num = "" ;
            }
            else if( s[i] == ']' )
            {
                a = st.top() ;
                st.pop() ;
                b = st.top() ;
                st.pop() ;
                if( !isdigit(b[0]) )
                {
                    st.push( b+a ) ;
                    a = st.top() ;
                    st.pop() ;
                    b = st.top() ;
                    st.pop() ;
                }
              

                for( j = 0 ; j < stoi(b) ; j++ )
                {
                    qtr += a ;
                }
                a = "" ;
                if( !st.empty() && !isdigit(st.top()[0]) )
                {
                    a = st.top() ;
                    st.pop() ;
                }
                    
                if( st.empty() )
                    res += qtr ;
                else{
                st.push(a + qtr) ;
                }
                qtr = "" ;
                flag = 0 ;
            }
            else 
            {
                if( flag == 0 && st.empty() )
                {
                    while( i < size && !isdigit(s[i]) )
                    {
                        res += s[i] ;
                        i++ ;
                    }
                    i-- ;
                }
                else
                {
                    while( !isdigit(s[i]) && s[i] != ']' )
                    {
                        str += s[i] ;
                        i++ ;
                    }
                    st.push(str) ;
                    str = "" ;
                    i-- ;
                }
            }
        }
        return res ;
    }
};
