/*
Auther  : B083040030 郭昱
Date    : 2021/4/13
Problem : 10195 The Knights Of The Round Table
*/
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{   
    double edge1, edge2, edge3, r;
    //cout << sqrt(0) << endl;
    while(cin >> edge1 >> edge2 >> edge3)
    {
        double edge_sum = edge1 + edge2 + edge3;
        edge_sum/=2;
        if(edge_sum==0)
            r = 0;
        else
            r = sqrt(edge_sum*(edge_sum-edge1)*(edge_sum-edge2)*(edge_sum-edge3)) / edge_sum;
        cout << "The radius of the round table is: " << fixed  << setprecision(3) << r << endl;
    } 
}
