#include<iostream>
#include <algorithm>
//#include <queue>

using namespace std;

class doll
{
public:
    int width;
    int height;
};

bool operator >(doll A, doll B)
{
    return (A.width > B.width) || (A.width == B.width && A.height > B.height);
}

bool operator <(doll A, doll B)
{
    return (A.width < B.width) || (A.width == B.width && A.height < B.height);
}

bool operator ==(doll A, doll B)
{
    return (A.width == B.width && A.height == B.height);
}

void swap(doll &A, doll &B)
{
    doll temp;
    temp = A;
    A = B;
    B = temp;
}



int main()
{
    int t, m;
    cin >> t;
    while(t--)
    {
        cin >> m;
        doll pool[m];
        for(int i=0; i<m; i++)
            cin >> pool[i].width >> pool[i].height;
        
        sort(pool, pool+m);
        //sort
        /*
        for(int i=0; i<m; i++)
            for(int j=1; j<m-i; j++)
                if(pool[j-1] > pool[j])
                    swap(pool[j-1], pool[j]);
        */
        //for(int i=0; i<m; i++)
            //cout << pool[i].width << " " << pool[i].height << endl;
        //cout << endl;

        /*
        for(int i=0; i<m; i++)
            for(int j=1; j<m-i; j++)
                if(pool[j-1].width > pool[j].width)
                    swap(pool[j-1], pool[j]);
        */
        //for(int i=0; i<m; i++)
            //cout << pool[i].width << " " << pool[i].height << endl;
        //cout << "counting appare times\n";
        
        doll nested[m+1];
        for(int i=0; i<m+1; i++)
            nested[i].height = nested[i].width = 0;
        
        int sum=-1;
        int j;
        for(int i=0; i<m; i++)
        {
            if(sum < 0)
            {
                nested[++sum] = pool[i];
                continue;
            }
            for(j=sum; !(pool[i].width > nested[j].width && pool[i].height > nested[j].height); j--);
            if(j>=0)
            {
                nested[j] = pool[i];
                for(j++; j<=sum; j++)
                    if(nested[j-1].height > nested[j].height || (nested[j-1].height == nested[j].height && nested[j-1].width > nested[j].width))
                        swap(nested[j-1], nested[j]);
            }
            else
            {
                nested[++sum] = pool[i];
                for(j=sum; j>0; j--)
                    if(nested[j-1].height > nested[j].height || (nested[j-1].height == nested[j].height && nested[j-1].width > nested[j].width))
                        swap(nested[j-1], nested[j]);
            }
        }
        //for(int i=0; i<=sum; i++)
            //cout << nested[i].width << " " << nested[i].height << endl;
        //int count;
        //for(count=0; nested[count].width!=0 || nested[count].height!=0; count++);

        cout << sum+1 << endl;
    }
}