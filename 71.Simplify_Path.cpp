/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/
class Solution {
public:
    string simplifyPath(string path) {
        
        int i, size = path.size(), flag = 0;
        if( size == 0 )
            return path;
        stack<string>s1;
        string str = "";
        for( i = 0; i < size; i++ )
        {
            if( path[i] != '/' )
                str += path[i];
            else if( path[i] == '/' )
            {
                if( i == size-1 )
                    flag = 1;
                if( str != "" )
                {
                    if( !s1.empty() && str == ".." )
                    {
                        s1.pop();
                    }
                    else if( str == ".." )
                    {
                    }
                    else if( str == "." )
                    { }
                    else if( path[i] == '/'  )
                    {
                        s1.push(str);
                    }
                    str = "";
                }
            }
            if( i == size-1 && flag == 0 )
            {
                if( str == ".." && !s1.empty())
                    s1.pop();
                else if( str == ".." )
                {}
                else if( str != "." )
                    s1.push(str);
                    
            }
        }

        str = "";
        if( s1.empty() )
        {
            str = '/';
            return str;
        }
        while( !s1.empty() )
        {
            str = '/' + s1.top() + str;
            s1.pop();
        }
        return str;
    }
};
