#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int number, N;
    int factor[10];
    cin >> number;
    while(number--)
    {
        cin >> N;
        if(N==1)
        {
            cout << 1 << endl;
            continue;
        }
        if(N==0)
        {
            cout << 0 << endl;
            continue;
        }
        for(int i=1; i<10; i++)
            factor[i] = 0;
        int i=N, j=9;
        while(i>1 && j>1)
        {
            if(i%j==0)
            {
                i /= j;
                factor[j]++;
            }
            else
            {
                j--;
            }
            //cout << i << " " << j << endl;
        }
        if(i==1)
        {
            for(int i=2; i<10; i++)
                for(int j=0; j<factor[i]; j++)
                    cout << i;
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
}