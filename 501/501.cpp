#include<iostream>

using namespace std;

int main()
{
    int K;//number of dataset
    int M;//size of A()
    int N;//size of u()
    int A[30001], u[30001];

    cin >> K;

    for(int k=0; k<K; k++)
    {
        //vvvvvvvvvvv input vvvvvvvv
        cin >> M >> N;
        for(int j=0; j<M; j++)
            cin >> A[j];
        for(int j=0; j<N; j++)
            cin >> u[j];
        //^^^^^^^^^^ input ^^^^^^^^^^
        
        //vvvvvvvvvvv output vvvvvvvv
        int i=0, B_box[30001], temp;
        for(int size=0; size<M; size++)
        {
            //ADD
            //temp = new int;
            temp = A[size];
            int j;
            //B_box[size] = new int;
            for(j=0; j<size; j++)
                if(B_box[j] > temp)
                    break;
            for(int x=size; x>j; x--)
                B_box[x] = B_box[x-1];
            B_box[j] = temp;

            //check
            /*
            for(int j=0; j<=size; j++)
                cout << *B_box[j] << " ";
            cout << endl;
            */

            //GET
            while(size == u[i]-1)
            {
                cout << B_box[i] << endl;
                i++;
                if(i==N)
                    break;
            }
            if(i==N)
                break;
        }
        if(k<K-1)
            cout << endl;
        //for(int j=0; j<M; j++)
        //    delete B_box[j];
        //^^^^^^^^^^ output ^^^^^^^^^^
        
    } 
    return 0;
}