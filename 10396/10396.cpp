#include<iostream>
#include<cmath>
#include<vector>
#include <algorithm>

using namespace std;
vector<int> ans[9];

void init(int N)
{
    for(int i=pow(10, N/2-1); i<(int)pow(10, N/2); i++)
    {
        for(int j=i; j<(int)pow(10, N/2); j++)
        {
            int v = i*j;
            if(v>pow(10, N-1) && (i%10!=0 || j%10!=0))
            {
                int digits[10] = {};
                int flag = 0;

                for(int k=i, l=0; l<N/2; k/=10, l++)
                    digits[k%10]++;
                for(int k=j, l=0; l<N/2; k/=10, l++)
                    digits[k%10]++;

                for(int k=v, l=0; l<N; k/=10, l++)
                    digits[k%10]--;
                for(int k=0; k<10; k++)
                    if(digits[k]!=0)
                        flag = 1;
                if(flag == 0 && v%2==0)
                    ans[N].push_back(v);
            }
        }
    }
    
    sort(ans[N].begin(), ans[N].end());
    
    for(int i=1; i<ans[N].size(); i++)
        if(ans[N][i-1] == ans[N][i])
        {
            //cout << ans[N][i];
            ans[N].erase(ans[N].begin()+i);
            i--;
        }
        
}

int main()
{
    init(4);
    init(6);
    init(8);

    int input;
    while(cin >> input)
    {
        for(int i:ans[input])
            cout << i << endl;
        cout << endl;
    }
}
    