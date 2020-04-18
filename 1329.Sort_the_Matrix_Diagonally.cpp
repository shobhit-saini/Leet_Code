/*
Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int row_size = mat.size() , col_size = mat[0].size() , i , j ;
        vector<int> v1 ;
        vector<vector<int>> v ;
        int k = 0 ;
        while( k != col_size )
        {
            v1.clear() ;
            
            for( j = k , i = 0 ; i < row_size && j < col_size ; j++ , i++ )
            {
                v1.push_back(mat[i][j]) ;
            }
            v.push_back(v1) ;
            
            k++ ;
        }
        k = 1 ; 
        while( k != row_size )
        {
            v1.clear() ;
            for( j = 0 , i = k ; i < row_size && j < col_size ; j++ , i++ )
            {
                v1.push_back(mat[i][j]) ;
            }
            v.push_back(v1) ;
            k++ ;
        }
        for( i = 0 ; i < v.size() ; i++ )
        {
           sort( v[i].begin() , v[i].end() ) ;
        }
        
        k = 0 ; 
        int l = 0 , m ;
        while( k != col_size )
        {
            
            for( j = k , i = 0, m = 0 ; i < row_size && j < col_size ; j++ , i++ , m++ )
            {
                mat[i][j] = v[l][m] ;
            }
            k++ ;
            l++ ;
        }
        k = 1 ; 
        while( k != row_size )
        {
            for( j = 0 , i = k , m = 0 ; i < row_size && j < col_size ; j++ , i++ , m++ )
            {
                mat[i][j] = v[l][m] ;
            }
            k++ ;
            l++;
        }
        return mat ;
    }
};
