#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int fstep = 1;
    int sstep = 1;
    int nstep = 1;
    for (int i = 1; i < n; n--)
    {
        nstep = fstep + sstep;
        fstep = sstep;
        sstep = nstep;
    }
    cout<<nstep;
    return 0;
}
