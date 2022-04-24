#include<iostream>
#include<iomanip>
#include<queue>

using namespace std;

struct node
{
    int point; // 
    int k; // the number of times the boot can be used
    int time; // the time from 1 to point
};

int main()
{
    int N;
    int A, B, M, L, K;
    //input
    cin >> N;
    while(N--)
    {
        cin >> A >> B >> M >> L >> K;
        
        //初始化f
        int f[A+B+1][A+B+1];
        for(int x=1; x<=A+B; x++)
            for(int y=1; y<=A+B; y++)
                if(x!=y)
                    f[x][y] = 2147483647/2; //無限大
                else
                    f[x][y] = 0;
        /*
        for(int x=1; x<=A+B; x++)
        {
            for(int y=1; y<=A+B; y++)
                if(f[x][y]!=2147483647/2)
                    cout << "\t" << f[x][y];
                else
                    cout << "\tinf";
            cout << endl;
        }
        //*/

        //輸入路徑
        int a, b, c;
        for(int i=0; i<M; i++)
        {
            cin >> a >> b >> c;
            f[a][b] = c;
            f[b][a] = c;
        }

        //floyd演算法
        for(int mid=1; mid<=A; mid++)
            for(int start=1; start<=A+B; start++)
                for(int goal=1; goal<=A+B; goal++)
                    if( f[start][goal] > (f[start][mid] + f[mid][goal]) )
                        f[start][goal] = f[start][mid] + f[mid][goal];
        
        //debug
        /*
        for(int x=1; x<=A+B; x++)
        {
            for(int y=1; y<=A+B; y++)
                if(f[x][y]!=2147483647/2)
                    cout << "\t" << f[x][y];
                else
                    cout << "\tinf";
            cout << endl;
        }
        //*/
        
        int dp[A+B+1][K+1];
        for(int i=0; i<=A+B; i++)
            for(int j=0; j<=K; j++)
                dp[i][j] = 2147483647/2;

        queue<node> que;
        node temp;
        temp.point = 1;
        temp.k = K;
        temp.time = 0;
        que.push(temp);
        dp[1][K] = 0;
        while(!que.empty())
        {
            /*
            if(que.front().point==A+B)
            {
                cout << que.front().time << endl;
                //break;
            }
            */

            int point = que.front().point;
            int k = que.front().k;
            que.pop();

            for(int i=1; i<=A+B; i++)
            {
                if(point==i);
                else if(f[point][i]==2147483647/2);
                else if(dp[i][k] > dp[point][k] + f[point][i])
                {
                    dp[i][k] = dp[point][k] + f[point][i];
                    temp.point = i;
                    temp.k = k;
                    temp.time = dp[i][k];
                    que.push(temp);
                }
                if(k>0 && f[point][i]<=L && dp[i][k-1] > dp[point][k])
                {
                    dp[i][k-1] = dp[point][k];
                    temp.point = i;
                    temp.k = k-1;
                    temp.time = dp[i][k-1];
                    que.push(temp);
                }
                
            }
            //debug
            /*
            cout << "\t" << point << endl;
            for(int j=0; j<=K; j++)
            {
                for(int i=1; i<=A+B; i++)
                    if(dp[i][j]==2147483647/2)
                        cout << "\tinf";
                    else
                        cout << "\t" << dp[i][j];
                cout << endl;
            }
            cout << endl;
            //*/
        }
        cout << dp[A+B][0] << endl;
        /*
        for(int i=1; i<=A+B; i++)
        {
            for(int j=0; j<=K; j++)
                if(dp[i][j]==2147483647/2)
                    cout << "\tinf";
                else
                    cout << "\t" << dp[i][j];
            cout << endl;
        }
        */
    }
    //end of while

    
}