#include<iostream>
#include<stdio.h>

using namespace std;

int money[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
long long int dp[12][6001];

int main()
{
    //dp
    //init
    for(int i=0; i<12; i++)
        for(int j=0; j<6001; j++)
            dp[i][j] = 0;
    for(int i=0; i<6001; i++)
        dp[1][i] = 1;
    for(int i=1; i<12; i++)
        dp[i][0] = 1;
    
    for(int i=2; i<12; i++)
        for(int j=1; j<6001; j++)
        {
            dp[i][j] += dp[i-1][j];
            if(j-money[i-1] >= 0)
                dp[i][j] += dp[i][j-money[i-1]];
        }            
    /*
    for(int i=1; i<4; i++)
    {
        for(int j=0; j<9; j++)
            printf("%3d", dp[i][j]);
        cout << endl;
    }
    */
    //dp[11][6000] = 181490736388615;
    float n;
    while( cin >> n && n )
    {
        int input = n*20;
        if(n>=100)
            printf("%.2f%17lld\n", n, dp[11][input]);
        else if(n>=10)
            printf(" %.2f%17lld\n", n, dp[11][input]);
        else
            printf("  %.2f%17lld\n", n, dp[11][input]);
    }
}