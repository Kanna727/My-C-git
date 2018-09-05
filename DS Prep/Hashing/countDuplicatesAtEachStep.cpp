#include <bits/stdc++.h>
using namespace std;

void countAtEachStep(long long int n, vector<long long int> &v){
    map<int, int> m;
    for(long long int i=0;i<n;i++){
        if(m[v[i]]==0) m[v[i]]=1;
        else m[v[i]]++;
        cout<<m[v[i]]<<" ";
    }
}

int main()
{
    long long int s, n;
    cin>>n;
    s=n;
    vector<long long int> v;
    while(n--) {
        long long int k;
        cin>>k;
        v.push_back(k);
    }

    countAtEachStep(s,v);
    cout<<endl;
    
    system("pause");
    return 0;
}