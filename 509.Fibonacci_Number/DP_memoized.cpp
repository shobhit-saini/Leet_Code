class Solution {
public:
    int cal(vector<int>&v, int N)
    {
        if(N == 0 || N == 1)
            return N;
        if(v[N] == -1)
            return v[N] = cal(v, N-1) + cal(v, N-2);
        else
            return v[N];
    }
    int fib(int N) {
        vector<int> v(N+1, -1);
        return cal(v, N);
    }
};
