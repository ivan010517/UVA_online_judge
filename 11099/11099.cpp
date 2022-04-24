#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int prime(int n)
{
    if(n==2)
        return 1;
    if(n<=1)
        return 0;
    for(int i=2; i<=(int)sqrt(n); i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}


int prime_table[78498];

void make_table()
{
    
    int sum=0, flag;
    prime_table[sum++] = 2;
    for(int i=3; i<=999983; i+=2)
    {
        flag = 1;
        for(int j=3; j<=(int)sqrt(i); j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            prime_table[sum++] = i;
    }
    //cout << sum << endl;
    
}

int factor_table[100][2];

void factorization(int n)
{
    int count=0;
    factor_table[0][0] = factor_table[1][0] = 0;
    for(int i=n, k=0; i>1; k++)
    {
        if(i%prime_table[k] == 0)
        {
            //return i*prime_table[k];
            if(factor_table[count][0]!=prime_table[k])
            {
                factor_table[++count][0]=prime_table[k];
                factor_table[count+1][0] = 0;
                factor_table[count][1] = 0;
            }
            factor_table[count][1]++;
            //cout << prime_table[k] << " ";
            i /= prime_table[k--];
        }
            
    }
    //cout << endl; 
}

void BFS(int n)
{
    priority_queue<int, vector<int>, greater<int> > pool;
    int base=1;
    for(int i=1; factor_table[i][0]!=0; i++)
        base *= factor_table[i][0];
    pool.push(base);

    int flag = 1;
    while(base <= n && !pool.empty())
    {
        base = pool.top();
        pool.pop();
        for(int i=1; factor_table[i][0]!=0; i++)
        {
            if((float)base*factor_table[i][0] <= 2000000)
                pool.push(base*factor_table[i][0]);
            else
            {
                break;
            }
        }
        
    }
    if(base<=2000000 && base>n)
        cout << base << endl;
    else
        cout << "Not Exist!\n";
}

void next_factor(int n)
{
    if(n==1)
    {
        cout << "Not Exist!\n";
        return;
    }
    int sum, i;
    for(i=1, sum=0; factor_table[i][0]!=0; i++)
        if(factor_table[i][1]==1)
            sum++;
    if( i==sum+1 )
        if( (double)n * factor_table[1][0] <= 2000000)
            cout << n * factor_table[1][0] << endl;
        else
            cout << "Not Exist!\n";
    else
        BFS(n);

}

int main()
{
    make_table();
    int n;
    while(cin >> n)
    {
        factorization(n);
        next_factor(n);
    }
}