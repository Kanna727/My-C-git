#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
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

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    erotesthenes(n);
    cout<<endl;
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    std::cout << "time elapsed: " << duration << endl;
    
    system("pause");
    return 0;
}

/*
    O(sqrt(n)loglog(n))
*/