#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<vector>

using namespace std;

map<int, bool> history;

int array_to_string(vector<int> array)
{
    int sum=0;
    for(int i=0; i<8; i++)
    {
        sum*=10;
        sum += abs(array[i]);
    }
    return sum;
}

int prime(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    for(int i=2; i<=(int)sqrt(n); i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    
    int ans, temp;
    for(int n=1; cin >> temp && temp; n++)
    {
        vector<int> array;
        array.push_back(temp);
        history.clear();
        for(int i=2; i<9; i++)
        {
            cin >> temp;
            array.push_back(temp);
        }
        array.push_back(0);
        history[array_to_string(array)] = true;
        
        queue<vector<int>> arr;

        //BFS
        arr.push(array);
        int count;
        for(count=0; !arr.empty() && array_to_string(arr.front())!=12345678; count++)
        {
            array = arr.front();
            
            for(int i=0; i<8; i++)
                for(int j=0; j<8; j++)
                    if( array[i]*array[j]<0 && prime(abs(array[i])+abs(array[j])) )//rule
                    {
                        array[8]++;
                        temp = array[j];
                        if(j>i)
                        {
                            for(int k=j; k>i; k--)
                                array[k] = array[k-1];
                            array[i] = temp;
                        }
                        else
                        {
                            for(int k=j; k<i; k++)
                                array[k] = array[k+1];
                            array[i] = temp;
                        }
                        if(!history[array_to_string(array)])
                        {
                            history[array_to_string(array)] = true;
                            arr.push(array);
                        }                        
                        array = arr.front();
                        
                        array[8]++;
                        temp = array[j];
                        if(j>i)
                        {
                            for(int k=j; k>i+1; k--)
                                array[k] = array[k-1];
                            array[i+1] = temp;
                        }
                        else
                        {
                            for(int k=j; k<i-1; k++)
                                array[k] = array[k+1];
                            array[i-1] = temp;
                        }
                        if(!history[array_to_string(array)])
                        {
                            history[array_to_string(array)] = true;
                            arr.push(array);
                        }
                        array = arr.front();
                    }
            arr.pop();
            
        }
        if(arr.empty())
            cout << "Case " << n << ": " << -1 << endl;
        else
            cout << "Case " << n << ": " << arr.front()[8] << endl;
    }
    
}