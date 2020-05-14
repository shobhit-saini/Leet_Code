/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<map>
using namespace std;

struct Trie
{
    map<char, Trie*>child;
    bool endofword;
};
Trie* Root = new Trie();
void Insert( string str )
{
    Trie* curr = Root;
    for( int i = 0; i < str.size(); i++ )
    {
        if( curr->child.find(str[i]) == curr->child.end() )
        {
            Trie* node = new Trie();
            node->endofword = false;
            curr->child[str[i]] = node;
            curr = node;
        }
        else
        {
            curr = curr->child[str[i]];
        }
    }
    curr->endofword = true;
}
bool Search( string str )
{
    Trie* curr = Root;
    for( int i = 0; i < str.size(); i++ )
    {
        if( curr->child.find(str[i]) != curr->child.end() )
            curr = curr->child[str[i]];
        else
            return false;
    }
    return curr->endofword;
    
}
bool Delete( Trie* curr, string str, int index )
{
    if( str.size() == index )
    {
        if( curr->endofword == false )
            return false;
        curr->endofword = false;
        return curr->child.size() == 0;
    }
    if( curr->child.find(str[index]) == curr->child.end() )
        return false;
    bool flag = Delete( curr->child[str[index]], str, index+1 );
    if( flag == true )
    {
        if( curr->child[str[index]]->endofword != true )
        {
            curr->child.erase(str[index]);
            return curr->child.size() == 0;
        }
        return false;
    }
    return false;
}
int main()
{
    Root->endofword = false;
    Insert( "ABC" );
    Insert("ABCD");
    if( Search( "ABC" ) )
        cout << " word Found!!! ";
    else
        cout << " word not Found!!! ";
    Trie* curr = Root;
    Delete( curr, "ABCD", 0 );
    if( Search( "ABCD" ) )
        cout << " word Found!!! ";
    else
        cout << " word not Found!!! ";
    return 0;
}
