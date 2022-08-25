#include<iostream>
using namespace std;
int main()
{
    char *s = new char[sizeof(char)];

    gets(s);
    cout<<s;
    return 0;
}