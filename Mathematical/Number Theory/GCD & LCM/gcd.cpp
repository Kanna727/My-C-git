#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    int gcdRes = gcd(a,b);
    cout<<"GCD: "<<gcdRes<<endl;
    return (a*b)/gcdRes; //since  a x b = LCM(a, b) * GCD (a, b)
}

int main()
{
    int a,b;
    std::cout << "Enter a: ";
    cin>>a;
    std::cout << "Enter b: ";
    cin>>b;

    cout<<"LCM: "<<lcm(a,b)<<endl;
    
    system("pause");
    return 0;
}

/* Time Complexity O(log min(a,b)) */