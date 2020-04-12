class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int size1 =arr1.size() , size2 = arr2.size() , i = 0 , j = 0 , res = 0 , ans = 0;
        bool flag ;
        sort( arr1.begin() , arr1.end() ) ;
        sort( arr2.begin() , arr2.end() ) ;
        while( i < size1 && j < size2 )
        {
            if( arr1[i] >= arr2[j] )
            {
                if( abs( arr1[i] - arr2[j] ) > d )
                    j++;
                else
                    i++ ;
            }
            else
            {
                if( abs( arr1[i] - arr2[j] ) > d )
                {
                    i++;
                    ans++ ;
                }
                else 
                    i++ ;
            }
        }
        return ans + size1 - i ;
    }
};
