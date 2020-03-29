class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>v;
        int i;
        string str = "";
        for(i = 1; i <= n; i++)
        {
            str = "";
            if(i % 3 == 0)
                str += "Fizz";
            if(i % 5 == 0)
                str += "Buzz";
            if(str == "")
                str += to_string(i);
            v.push_back(str);       
        }
        return v;
    }
};
