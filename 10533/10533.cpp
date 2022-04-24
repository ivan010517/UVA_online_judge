/*
Auther  : B083040030 郭昱
Date    : 2021/4/21
Problem : 10533 - Digit Primes
*/

#include<iostream>
#include<cmath>

using namespace std;

int a[1000000];

int prime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    int max = (int)sqrt(n);
    for(int i=2; i<max+1; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int D_prime(int n)
{
    if(prime(n))
    {
        int temp=0;
        for(int j=n;j!=0;j/=10)
            temp += j%10;
        if(prime(temp))
            return 1;
    }
    return 0;
}

int main()
{
    int sum=0;
    for(int i=0; i<=1000000; i++)
    {
        if(D_prime(i))
            sum++;
        a[i] = sum;
    }
    int N, low, high;
    cin >> N;
    for(int l=0; l<N; l++)
    {
        cin >> low >> high;
        cout << a[high] - a[low-1] << endl;
        
    }
    return 0;
    
}

