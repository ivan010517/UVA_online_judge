#include<iostream>
#include<cmath>

using namespace std;

int Prime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;

    for(int i=2; i<(int)sqrt(n)+1; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int n;
    while(cin >> n && n!=0)
    {
        int low, high;
        for(low=n; Prime(low)==0; low--);
        for(high=n; Prime(high)==0; high++);
        cout << high - low << endl;
    }
}