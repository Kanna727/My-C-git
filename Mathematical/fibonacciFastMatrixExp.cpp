#include <bits/stdc++.h>
using namespace std;

void multiply(int F[2][2], int M[2][2]){
    int t[2][2];
    for(int i=0; i<2;i++){
        for(int j=0; j<2;j++){
            t[i][j]= 0;
            for(int k=0;k<2;k++){
                t[i][j] += F[i][k] * M[k][j];
            }
        }
    }

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            F[i][j] = t[i][j];            
        }
    }
}

void power(int F[2][2], int n){
    if (n==0 || n==1) return;
    int M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);
    if(n & 1) multiply(F, M);
}

int fib(int n){
    if(n==0) return 0;
    int F[2][2] = {{1,1},{1,0}};
    power(F, n-1);
    return F[0][0];
}

int main()
{
    std::cout << "Enter the required term of fibonacci sequence: ";
    int n;
    cin>>n;

    cout<<fib(n)<<endl;
    
    system("pause");
    return 0;
}