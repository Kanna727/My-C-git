#include <bits/stdc++.h>
using namespace std;

float pow(int b, int p){
    float temp;
    if (p==0) {
        return 1;
    }

    temp = pow(b, p/2);

    if (p%2==0) {
        return temp*temp;
    } else {
        if(p>0){
            return b*temp*temp;
        } else {
            return (temp*temp)/b;
        }
    }
}

int main()
{
    std::cout << "Enter base: ";
    int b;
    cin>>b;
    std::cout << "Enter the power: ";
    int p;
    cin>>p;

    cout<<pow(b, p)<<endl;
    
    system("pause");
    return 0;
}