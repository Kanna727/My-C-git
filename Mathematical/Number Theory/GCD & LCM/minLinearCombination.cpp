/*
    PROBLEM STATEMENT: Find the non-zero values of x & y, such that xa + yb is minimum postive number, where a and b are positive
*/

#include <bits/stdc++.h>
using namespace std;

int minLinComb(int a, int b, int &x, int &y){
    if(b == 0) {
        x=1;
        y=0;
        return a;
    }
    int xt, yt;
    int gcd =  minLinComb(b, a%b, xt, yt);

    x = yt;
    y = xt - (a/b)*yt;

    return gcd;
}

int main()
{
    int a,b, x, y;
    std::cout << "Enter a & b: ";
    cin>>a>>b;

    minLinComb(a,b, x, y);
    
    cout<<"x: "<<x<<" y: "<<y<<endl;
    system("pause");
    return 0;
}

/* O(log min(a,b)) */