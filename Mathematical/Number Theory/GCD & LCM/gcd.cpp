#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int a,b;
    std::cout << "Enter a: ";
    cin>>a;
    std::cout << "Enter b: ";
    cin>>b;

    cout<<gcd(a,b)<<endl;
    
    system("pause");
    return 0;
}