
// C++ program to print primes smaller than n using
// Sieve of Sundaram.
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
 
// Prints all prime numbers smaller
long long int SieveOfSundaram(long long int n)
{
    // In general Sieve of Sundaram, produces primes smaller
    // than (2*x + 2) for a number given number x.
    // Since we want primes smaller than n, we reduce n to half
    long long int nNew = (n-2)/2;
 
    // This array is used to separate numbers of the form i+j+2ij
    // from others where  1 <= i <= j
    bool marked[nNew + 1];
 
    // Initalize all elements as not marked
    memset(marked, false, sizeof(marked));
 
    // Main logic of Sundaram.  Mark all numbers of the
    // form i + j + 2ij as true where 1 <= i <= j
    for (long long int i=1; i<=nNew; i++)
        for (long long int j=i; (i + j + 2*i*j) <= nNew; j++)
            marked[i + j + 2*i*j] = true;
 
    // Since 2 is a prime number
    if (n > 2)
        cout << 2 << " ";
 
    // Print other primes. Remaining primes are of the form
    // 2*i + 1 such that marked[i] is false.
    for (long long int i=1; i<=nNew; i++)
        if (marked[i] == false)
            cout << 2*i + 1 << " ";
}
 
// Driver program to test above
int main(void)
{

    long long int n ;
    cin>>n;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    SieveOfSundaram(n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();
    std::cout << "time elapsed: " << duration << endl;
    cout<<endl;
    system("pause");
    return 0;
}