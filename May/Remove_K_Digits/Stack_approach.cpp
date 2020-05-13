class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int i = 0, size = num.size();
        string res = "";
        if( k == size )
            return "0";
        stack<char>s;
        while( i < size )
        {
            while( k > 0 && !s.empty() && s.top() > num[i] )
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
            i++;
        }
        while( k > 0 )
        {
            s.pop();
            k--;
        }
        while( !s.empty() )
        {
            char c = s.top();
            s.pop();
            res += c;
        }
        reverse( res.begin(), res.end() );
        i = 0;
        while( res[i] == '0' && res.size() > 1 )
        {
            res.erase(0, 1);
        }
        return res;
    }
};
