#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *a = new int[n];
    int *b = new int[n];
    b[0] = 0;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                b[i] = 1;
                b[j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(b[i] == 0)
            cout<<a[i]<<endl;
    }
    return 0;
}
