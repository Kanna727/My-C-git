#include <bits/stdc++.h>
using namespace std;

int logarithm(int a, int b){
    int count =0;
    while(a /= b) count++;
    return count;
}

int main()
{
    int a, b;
    std::cout << "Enter a: ";
    cin>>a;
    std::cout << "Enter base: ";
    cin>>b;

    cout<< logarithm(a,b)<<endl;
    
    system("pause");
    return 0;
}