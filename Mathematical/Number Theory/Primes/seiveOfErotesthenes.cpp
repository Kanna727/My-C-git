#include <bits/stdc++.h>
using namespace std;

void erotesthenes(long long int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for(long long int p = 2; p*p<=n; p++){
        if(prime[p]){
            for(long long int i = p*2; i<=n; i+=p){
                prime[i] =false;
            }
        }
    }

    for(long long int p=2; p<=n;p++){
        if(prime[p]) cout<<p<<" ";
    }
}

int main()
{
    long long int n;
    std::cout << "Enter the number: ";
    cin>>n;

    erotesthenes(n);
    cout<<endl;
    
    //system("pause");
    return 0;
}

/*
    O(sqrt(n)loglog(n))
*/