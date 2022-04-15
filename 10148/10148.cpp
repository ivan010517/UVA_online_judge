#include<iostream>

using namespace std;

int n;
int AD, run_num;

struct runner
{
    int begin;
    int end;
};

void swap(struct runner &a,struct runner &b)
{
    struct runner temp;
    temp = a;
    a = b;
    b = temp;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    
    cin >> n;
    while(n--)
    {
        cin >> AD >> run_num;
        struct runner run[run_num];
        int a, b;
        for(int i=0; i<run_num; i++)
        {
            cin >> a >> b;
            if(a>b)
            {
                run[i].begin = b;
                run[i].end = a;
            }
            else
            {
                run[i].begin = a;
                run[i].end = b;
            }
        }

        for(int i=0; i<run_num; i++)
            for(int j=1; j<run_num-i; j++)
                if(run[j-1].end > run[j].end)
                    swap(run[j], run[j-1]);
        //for(int i=0; i<run_num; i++)
        //    cout << run[i].begin << " " << run[i].end << endl;

        int M=0;
        int count;
        bool array[20002];
        for(int i=0; i<20002; i++)
            array[i] = false;
        for(int i=0; i<run_num; i++)
        {
            count=0;
            for(int j=run[i].begin; j<=run[i].end; j++)
                if(array[j+10000])
                    count++;

            int plus=0;
            if(run[i].end-run[i].begin<AD)
            {
                for(int j=run[i].end; j>=run[i].begin; j--)
                    array[j+10000] = true;
            }
            else
            {
                for(int j=run[i].end; j>=run[i].end-(AD-count)+1-plus; j--)
                    if(!array[j+10000])
                        array[j+10000] = true;
                    else
                        plus++;
                //cout << i << plus << endl;
            }
        }
        for(int i=0; i<20002; i++)
            if(array[i])
                M++;
        cout << M << endl;
        for(int i=0; i<20002; i++)
            if(array[i])
                cout << i-10000 << endl;
        
        if(n)
            cout << endl;
    }
}