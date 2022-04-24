/*
Auther  : B083040030 郭昱
Date    : 2021/2/25
Problem : 10323 - Factorial! You Must be Kidding!!!
*/
#include<iostream>

using namespace std;

long long factorial(int);
long long fact[15];

int main()
{   
    int input;
    while( (cin >> input) )
    {
        if(input < 0 && input%2==-1)
            cout << "Overflow!\n";
        else if(input < 8)
            cout << "Underflow!\n";
        else if(input > 13)
            cout << "Overflow!\n";
        else
            cout << factorial(input) << endl;
    }
}

long long factorial(int n)
{
    if(fact[n]!=0)
           return fact[n];
    long long temp=0;
    if(n==0)
        temp = 1;
    else if(n>0)
        temp =  n * factorial(n-1);
    fact[n] = temp;
    return temp;
}
