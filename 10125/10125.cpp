#include<iostream>

using namespace std;

void sort(int a[], int size)
{
    int temp;
    for(int i=0; i<size; i++)
        for(int j=1; j<size-i; j++)
            if(a[j-1] > a[j])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
}

int search(int a[], int n)
{
    for(int i=n-1; i>=0; i--)
        for(int j=n-1; j>=0; j--)
            for(int k=n-1; k>=0; k--)
                for(int l=n-1; l>=0; l--)
                    if(a[l]+a[k]+a[j] == a[i])
                        if(a[l]!=a[k] && a[l]!=a[j] && a[l]!=a[i] && a[k]!=a[j] && a[k]!=a[i] && a[j]!=a[i])
                        {
                            //cout << a[l] << a[k] << a[j] << endl;
                            cout << a[i] << endl;
                            return 1;
                        }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n!=0)
    {
        bool flag = 0;
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a, n);
        flag = search(a, n);
        if(flag==0)
            cout << "no solution\n";
        cin >> n;
    }
}