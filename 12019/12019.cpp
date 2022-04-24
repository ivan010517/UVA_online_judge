#include<iostream>

using namespace std;

int main()
{
    int n, M, D, days;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        days = 0;
        cin >> M >> D;
        if(M>1)
            days += 31;
        if(M>2)
            days += 28;
        if(M>3)
            days += 31;
        if(M>4)
            days += 30;
        if(M>5)
            days += 31;
        if(M>6)
            days += 30;
        if(M>7)
            days += 31;
        if(M>8)
            days += 31;
        if(M>9)
            days += 30;
        if(M>10)
            days += 31;
        if(M>11)
            days += 30;
        days += D;
        days %= 7;
        if(days==6)
            cout << "Thursday\n";
        if(days==0)
            cout << "Friday\n";
        if(days==1)
            cout << "Saturday\n";
        if(days==2)
            cout << "Sunday\n";
        if(days==3)
            cout << "Monday\n";
        if(days==4)
            cout << "Tuesday\n";
        if(days==5)
            cout << "Wednesday\n";
         
        

    }
}