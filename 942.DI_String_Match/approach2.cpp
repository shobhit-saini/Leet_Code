class Solution {
public:
    vector<int> diStringMatch(string S) {
        
        int i , size = S.size() , temp , k ;
        vector<int> v;
        int min = 0 , max = size ;
        for( i = 0; i < size ; i++ )
        {
            if( S[i] == 'I' )
            {
                v.push_back(min++) ;
            }
            else if( S[i] == 'D' )
            {
                v.push_back(max--);
            }
        }
        if( S[i - 1] == 'I' )
            v.push_back(min++) ;
        else 
            v.push_back(max--) ;
        return v ;
    }
};
