class Solution {
public:
    bool isPalindrome(int x) {
        int reversed_half = 0;
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        while(x > reversed_half)
        {
            reversed_half = 10*reversed_half + x % 10;
            x = x/10;
        }
        return x == reversed_half || x ==  reversed_half/10;
    }
};
