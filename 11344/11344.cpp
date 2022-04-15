#include<iostream>

using namespace std;

int mod(int, char[]);

int main()
{
    /*
    char M[1001];
    int n;
    cin >> M >> n;
    cout << mod(n, M) << endl;
    */
    //變數宣告
    int N; //N筆資料輸入
    char **M_input; //被除數，以字串之形式讀入
    int **S; //除數集合，S[x][0]表第x個集合內的元素數量

    //input
    cin >> N;
    M_input = new char*[N];
    S = new int*[N];
    for(int i=0; i<N; i++)
    {
        M_input[i] = new char[1001];
        S[i] = new int[13];
        cin >> M_input[i];
        cin >> S[i][0];
        for(int j=1; j<=S[i][0]; j++)
        {
            cin >> S[i][j];
        }
    }

    //output
    for(int i=0; i<N; i++)
    {
        for(int j=1; j<=S[i][0]; j++)
        {
            if(mod(S[i][j], M_input[i]) != 0)
            {
                cout << M_input[i] << " - Simple.\n";
                break;
            }
            if(j==S[i][0])
            {
                cout << M_input[i] << " - Wonderful.\n";
            }
        }
        delete S[i];
        delete M_input[i];
    }
    delete S;
    delete M_input;
}

int mod(int divide, char M_input[])
{
    char M[1001];
    int i;
    for(i=0; M_input[i]!='\0'; i++)
        M[i] = M_input[i];
    M[i] = '\0';

    int temp=0;
    for(i=0; M[i]!='\0'; i++)
    {
        temp *= 10;
        temp += M[i] - '0';
        M[i] = '0';
        if(temp >= divide)
        {
            if(temp % divide >= 10)
            {
                M[i-1] = (temp % divide)/10 + '0';
                M[i] = (temp % divide)%10 + '0';
                i-=2;
                temp=0;
            }
            else
            {
                M[i] = temp % divide + '0';
                i--;
                temp=0;
            }
        }
    }
    return temp;
}