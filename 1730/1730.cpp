#include<iostream>
#include<cmath>

using namespace std;

long long int MSLCM(int n)
{
    long long int temp, right;
    long long int sum=0;
    for(int i=1; i<=n;)
    {
        temp = (int) n / i;
        right = (int)n/temp;
        sum += temp * (i+right) * (right-i+1)/2;
        i = right+1;
    }
    return sum-1;
}

int main()
{
    
    int N;
    while(cin >> N && N!=0)
    {
        cout << MSLCM(N) << endl;
    }
}