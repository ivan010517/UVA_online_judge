/*
Auther  : B083040030 郭昱
Date    : 2021/2/25
Problem : 10323 - Factorial! You Must be Kidding!!!
*/
#include<iostream>

using namespace std;

int main()
{   
    int M; // input number
    while(cin >> M)
    {
        int N;
        int remainder=0;
        for(N=0; remainder!=0 || N==0; N++)
        {            
            remainder = remainder*10 + 1;
            remainder %= M;
        }
        cout << N << endl;
    }

    return 0;
}

