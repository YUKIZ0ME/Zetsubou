#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char ch, ch1;
    int n = 0;
    while(cin.get(ch))
    {
        if (isalpha(ch))
            n++;
        if (isalpha(ch) && isspace(ch1))
        {
            n = 1;
        }
        ch1 = ch;
    }
    cout<<n;
    return 0;
}
