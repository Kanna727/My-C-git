#include <bits/stdc++.h>
using namespace std;
map<int, int> map1;
map<int, int> map2;

bool isSubset(int arr1[], int arr2[], int m, int n){
    
    for(int i = 0; i < n; i++)
    {
        if(!map1[arr2[i]]) return 0;
    }
    return 1;
}

int main()
{
    int m, n, arr1[100], arr2[100];
    cout<<"Enter size of array 1: ";
    cin>>m;
    cout<<endl;
    while(m--){
        cout<<"Enter element "<<m<<" of array 1: ";
        cin>>arr1[m];
        map1[arr1[m]]++;
        std::cout << endl;
    }
    cout<<"Enter size of array 2: ";
    cin>>n;
    cout<<endl;
    while(n--){
        cout<<"Enter element "<<n<<" of array 2: ";
        cin>>arr2[n];
        map2[arr2[m]]++;
        std::cout << endl;
    }

    if(isSubset(arr1, arr2, m, n))
        cout<<"arr2 is a subset of arr1";
    else
        cout<<"arr2 is not a subset of arr1";
    
    //system("pause");
    return 0;
}