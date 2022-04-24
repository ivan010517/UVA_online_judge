#include<iostream>
#include<stdio.h>

using namespace std;

int min(int a, int b)
{
    if(a>b)
        return b;
    else    
        return a;
}

int main()
{
    int path_num, node_num;
    int x, y, capacity;
    int begin, end, peo_num;
    for(int Scenario=1; cin >> node_num >> path_num && path_num && node_num; Scenario++)
    {
        int table[node_num+1][node_num+1];
        for(int x=0; x<=node_num; x++)
            for(int y=0; y<=node_num; y++)
                table[x][y]=0;
        
        for(int i=0; i<path_num; i++)
        {
            cin >> x >> y >> capacity;
            table[x][y] = table[y][x] = capacity;
        }
        cin >> begin >> end >> peo_num;
        for(int mid=1; mid<=node_num; mid++)
            for(int x=1; x<=node_num; x++)
                for(int y=1; y<=node_num; y++)
                    if(table[x][y] < min(table[x][mid], table[mid][y]) )
                        table[x][y] = min(table[x][mid], table[mid][y]);
        
        cout << "Scenario #" << Scenario << endl;
        //cout << table[begin][end] << endl;
        cout << "Minimum Number of Trips = " << (peo_num-1)/(table[begin][end]-1) + 1 << endl << endl;

        /*
        for(int x=1; x<=node_num; x++)
        {
            for(int y=1; y<=node_num; y++)
                printf("%3d", table[x][y]);
            cout << endl;
        }
        */
        
    }
}