#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        vector<string> v;
        string r;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') {
                v.push_back(r);
                r.clear();
            }
            else {
                r = r+s[i];
            }
        }
        v.push_back(r);

        int n= stoi(v[0]);
        int i,j;
        cin>>i>>j;
        int index = n*(i-1) + (j);
        //int index = i*j;
        
        index < v.size() ? cout<<stoi(v[index+1])<<endl : cout<<"Doesn't exist"<<endl;

        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<",";
        // }
        //cout<<s<<endl;
    }
    system("pause");
    return 0;
}