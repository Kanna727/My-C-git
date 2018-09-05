#include <bits/stdc++.h>
using namespace std;

void countSetBits(int n){
    int count = 0;
    while(n){
        n = n&(n-1);
        count++;
    }

    std::cout << "No of set bits are: "<< count << endl;
}

int main()
{
    int n;
    std::cout << "Enter the number: ";
    cin>>n;

    countSetBits(n);
    
    system("pause");
    return 0;
}