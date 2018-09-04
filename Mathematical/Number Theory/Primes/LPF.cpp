#include <bits/stdc++.h>
using namespace std;

void printLPF(long long int n){
    vector<int> LPF(n+1, 0);

    LPF[1]=1;

    for(long long int p=2;p<=n;p++){
        if(LPF[p]==0){
            LPF[p]=p;

            for(long long int i=p*2;i<=n;i+=p){
                if(LPF[i]==0) LPF[i]=p;
            }
        }
    }

    for(long long int i=1;i<=n;i++){
        cout << "Least Prime factor of "
             << i << ": " << LPF[i] << "\n";
    }
}

int main()
{
    long long int n;
    std::cout << "Enter n: ";
    cin>>n;

    printLPF(n);
    cout<<endl;
    
    system("pause");
    return 0;
}