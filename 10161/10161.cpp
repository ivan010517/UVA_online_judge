#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    unsigned N;
    //cout << sqrt(2000000000) << endl;
    while(cin >> N && N!=0)
    {
        int low, mid;
        low = (int)sqrt(N-1);
        mid = (((double)low*low)+1 + ((double)low+1)*(low+1)) / 2;
        //cout << mid << " " << low << endl;
        if(low%2==1)                            //start from left top
            if(N<mid)
                cout << low-(mid-N)+1 << " " << low+1;
            else
                cout << low+1 << " " << low-(N-mid)+1;
        else                                    //start from right bot
            if(N<mid)
                cout << low+1 << " " << low-(mid-N)+1;
            else
                cout << low-(N-mid)+1 << " " << low+1;
        cout << endl;
    }
}